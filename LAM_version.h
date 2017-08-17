
#ifndef __LAM_VERSION_H__
#define __LAM_VERSION_H__

#if !defined (LAM_VERSION_MAJOR)
#define LAM_VERSION_MAJOR 1
#endif

#if !defined (LAM_VERSION_MINOR)
#define LAM_VERSION_MINOR 0
#endif

#if !defined (LAM_VERSION_MICRO)
#define LAM_VERSION_MICRO 0
#endif

#if !defined (LAM_VERSION_FULLVER)
#define LAM_VERSION_FULLVER 1000
#endif

#if !defined (LAM_VERSION_CREATE_DATE)
#define LAM_VERSION_CREATE_DATE "17-08-2017 12:27 +00200 (THR 17 AUG 2017 GMT+2)"
#endif
/*
Set this value to latest build date/time
*/
#if !defined (LAM_VERSION_BUILD_DATE)
#define LAM_VERSION_BUILD_DATE " "
#endif

#if !defined (LAM_VERSION_AUTHOR)
#define LAM_VERSION_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_VERSION_DESCRIPT)
#define LAM_VERSION_DESCRIPT "Library version class."
#endif

#include <string>
#include <memory>
#include <tuple>

namespace lam{

	namespace lam_common{

    class VersionInfo {

	    public:

		   VersionInfo(_In_ const VersionInfo &) = delete;

		   VersionInfo & operator=(_In_ const VersionInfo &) = delete;

		   ~VersionInfo() = default;

		   std::shared_ptr<VersionInfo> getVersionInfo();

		   inline unsigned int getVersionMajor() const;

		   inline unsigned int getVersionMinor() const;

		   inline unsigned int getVersionMicro() const;

		   inline unsigned int getFullVersion() const;

		   const std::string getProjectName() const;

		   const std::string getLibName() const;

		   const std::string getLibPurpose() const;

		   const std::string getLibType() const;

		   const std::string getLibArch() const;

		   const std::string getLibOS() const;

		   const std::string getLibCPU() const;

		   const std::string getLibCreateDate() const;

		   const std::string getLibLastBuild() const;

		   const std::string getLibCompilerVer() const;

		   std::tuple<unsigned int, 
		              unsigned int,
					  unsigned int,
					  unsigned int,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string,
					  std::string> getLibDescription() const;

		private:

		   // Default Constructor
		   VersionInfo();

		   // Initialize to concrete
		   VersionInfo(_In_ const unsigned int, 
		               _In_ const unsigned int,
					   _In_ const unsigned int,
					   _In_ const unsigned int,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *,
					   _In_ const char *);

		   unsigned int m_VersionMajor;

		   unsigned int m_VersionMinor;

		   unsigned int m_VersionMicro;

		   unsigned int m_FullVersion;

	       std::string  m_ProjectName;

		   std::string  m_LibName;

		   std::string  m_LibPurpose;

		   std::string  m_LibType;

		   std::string  m_LibArch;

		   std::string  m_LibOS;

		   std::string  m_LibCPU;

		   std::string  m_LibCreateDate;

		   std::string  m_LibLastBuild;

		   std::string  m_LibCompilerVer;

       };
#include "LAM_version.inl"
   }
}


#endif /*__LAM_VERSION_H__*/