
#ifndef __LAM_PROCESS_HEAP_H__
#define __LAM_PROCESS_HEAP_H__

#if !defined (LAM_PROCESS_HEAP_MAJOR)
#define LAM_PROCESS_HEAP_MAJOR 1
#endif

#if !defined (LAM_PROCESS_HEAP_MINOR)
#define LAM_PROCESS_HEAP_MINOR 0
#endif

#if !defined (LAM_PROCESS_HEAP_MICRO)
#define LAM_PROCESS_HEAP_MICRO 0
#endif

#if !defined (LAM_PROCESS_HEAP_FULLVER)
#define LAM_PROCESS_HEAP_FULLVER 1000
#endif

#if !defined (LAM_PROCESS_HEAP_CREATE_DATE)
#define LAM_PROCESS_HEAP_CREATE_DATE "17-03-2018 11:09 +00200 (SAT 17 MAR 2018 GMT+2)"
#endif

//
//	Set this value after successful build date/time
//
#if !defined (LAM_PROCESS_HEAP_BUILD_DATE)
#define LAM_PROCESS_HEAP_BUILD_DATE " "
#endif

#if !defined (LAM_PROCESS_HEAP_AUTHOR)
#define LAM_PROCESS_HEAP_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_PROCESS_HEAP_DESCRIPT)
#define LAM_PROCESS_HEAP_DESCRIPT "Process heap monitoring functionality."
#endif

#include <Windows.h>
#include <list>
#include <stdexcept>

namespace lam {
	namespace system {

		//
		//	Declare class ProcessHeapInfo
		//  which will collect varying time snapshots of process heap usage.

		//

		

#if !defined (PROCESS_HEAP_INFO_ERROR)
#define PROCESS_HEAP_INFO_ERROR(msg)  \
	std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << (msg) << "," << "system error value: " << std::hex << "0x" << GetLastError() << "\n"; \
	std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n"; \
	throw std::runtime_error(msg);
#endif

		class ProcessHeapInfo {

		  private:

			struct heap {

				PVOID m_lpData; // this pointer is beign set in ctor.
				DWORD m_cbData;
				BYTE  m_cbOverhead;
				BYTE  m_iRegionIndex;
				WORD  m_wFlags;
				union {
					struct {
						HANDLE m_hMem;
						DWORD  m_dwReserved[3];
					} m_Block;
					struct {
						DWORD   m_dwCommitedSize;
						DWORD   m_dwUncommitedSize;
						LPVOID  m_lpFirstBlock;
						LPVOID  m_lpLastBlock;
					}m_Region;
				};

			}m_heap;

			int             m_nstates;     // number of heap snapshots
			WORD            m_flags;        // flag to switch between block/region data.
			HANDLE          m_heapHandle;   // handle to process heap
			HANDLE          m_procHandle;  // handle to this process
			DWORD           m_procID;	   // ID of this process.
			bool            m_lock_heap;    // lock/unlock heap during walk operation.
			std::list<heap> m_heapList;    // Process heap varying state list (snapshots).
		   
			
			public:

				ProcessHeapInfo() = delete;

				ProcessHeapInfo(_In_ const int, _In_ const WORD); 
								
				ProcessHeapInfo(_In_ const ProcessHeapInfo &) = delete;

				~ProcessHeapInfo();
			
				ProcessHeapInfo & operator=(_In_ const ProcessHeapInfo &) = delete;


				// Member procedures

				// Accessors

				int  get_nstates() const;

				WORD get_flags()   const;

				HANDLE get_heapHandle() const;

				HANDLE get_procHandle() const;

				DWORD  get_procID() const;

				bool   get_heap_lock() const;

				const std::list<heap> & get_heapList() const; // beware of object lifetime here!!

				std::list<heap>::const_iterator get_heapListIterator() const;

				void print_heap_state() const;

				// Mutators

				void heap_enumerate();

				
			

			

			
		};
	}
}


#endif /*__LAM_PROCESS_HEAP_H__*/