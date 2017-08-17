
#include "LAM_version.h"

lam::lam_common::VersionInfo::VersionInfo()
:
m_VersionMajor{ 9999 },
m_VersionMinor{ 9999 },
m_VersionMicro{ 9999 },
m_FullVersion{ 10000000 },
m_ProjectName{ " " },
m_LibName{ " " },
m_LibPurpose{ " " },
m_LibType{ " " },
m_LibArch{ " " },
m_LibOS{ " " },
m_LibCPU{ " " },
m_LibCreateDate{ " " },
m_LibLastBuild{ " " },
m_LibCompilerVer{ " " } {}

lam::lam_common::VersionInfo::VersionInfo(_In_ const unsigned int VersionMajor,
	                                      _In_ const unsigned int VersionMinor,
	                                      _In_ const unsigned int VersionMicro,
	                                      _In_ const unsigned int FullVersion,
	                                      _In_ const char *pProjectName,
	                                      _In_ const char *pLibName,
	                                      _In_ const char *pLibPurpose,
	                                      _In_ const char *pLibType,
	                                      _In_ const char *pLibArch,
	                                      _In_ const char *pLibOS,
	                                      _In_ const char *pLibCPU,
	                                      _In_ const char *pLibCreateDate,
	                                      _In_ const char *pLibLastBuild,
	                                      _In_ const char *pLibCompilerVer)
	:
	m_VersionMajor{ VersionMajor },
	m_VersionMinor{ VersionMinor },
	m_VersionMicro{ VersionMicro },
	m_FullVersion{ FullVersion },
	m_ProjectName{ pProjectName },
	m_LibName{ pLibName },
	m_LibPurpose{ pLibPurpose },
	m_LibType{ pLibType },
	m_LibArch{ pLibArch },
	m_LibOS{ pLibOS },
	m_LibCPU{ pLibCPU },
	m_LibCreateDate{ pLibCreateDate },
	m_LibLastBuild{ pLibLastBuild },
	m_LibCompilerVer{ pLibCompilerVer } {}

std::shared_ptr<lam::lam_common::VersionInfo>
lam::lam_common::VersionInfo::getVersionInfo(){
	
	return std::make_shared<VersionInfo>(new VersionInfo{1,0,0,1000,
	                                     "Atmosphere Model",
										 "LibAtmosModelCXX",
										 "Atmosphere simulation and modelling",
										 "static .lib",
										 "x64",
										 "Windows",
										 "Intel Core i7 4770 HQ",
										 "Date: 2017-08-17 Time: 15:24 PM GMT+2",
										 "Date: To be specified",
										 "ICL: 15.0.2.179 Build 20150121"});
}

const std::string lam::lam_common::VersionInfo::getProjectName() const {
	return (this->m_ProjectName);
}

const std::string lam::lam_common::VersionInfo::getLibName() const {
	return (this->m_LibName);
}

const std::string lam::lam_common::VersionInfo::getLibPurpose() const {
	return (this->m_LibPurpose);
}

const std::string lam::lam_common::VersionInfo::getLibType() const {
	return (this->m_LibType);
}

const std::string lam::lam_common::VersionInfo::getLibArch() const {
	return (this->m_LibArch);
}

const std::string lam::lam_common::VersionInfo::getLibOS() const {
	return (this->m_LibOS);
}

const std::string lam::lam_common::VersionInfo::getLibCPU() const {
	return (this->m_LibCPU);
}

const std::string lam::lam_common::VersionInfo::getLibCreateDate() const {
	return (this->m_LibCreateDate);
}

const std::string lam::lam_common::VersionInfo::getLibLastBuild() const {
	return (this->m_LibLastBuild);
}

const std::string lam::lam_common::VersionInfo::getLibCompilerVer() const {
	return (this->m_LibCompilerVer);
}

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
		   std::string > lam::lam_common::VersionInfo::getLibDescription() const {

			   return (std::make_tuple(this->m_VersionMajor,
			                           this->m_VersionMinor,
									   this->m_VersionMicro,
									   this->m_FullVersion,
									   this->m_ProjectName,
									   this->m_LibName,
									   this->m_LibPurpose,
									   this->m_LibType,
									   this->m_LibArch,
									   this->m_LibOS,
									   this->m_LibCPU,
									   this->m_LibCreateDate,
									   this->m_LibLastBuild,
									   this->m_LibCompilerVer));
}



