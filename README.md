# Weather Radar SImulation and Modeling

Currently Doppler Weather Radar modeling and simulation is being actively developed.
Rest of the library models, mainly cloud dynamics are put on hold till radar
modeling will be finished.
Critical part of the EM wavelength scattering is based on T-Matrix mathods developed
by Dr. Mishchenko (single particle scattering) and Dr. Xu code (aggregated ensemble 
of particles scattering).
Aforementioned models are coded in Fortran 77 and will be called by C wrappers.
