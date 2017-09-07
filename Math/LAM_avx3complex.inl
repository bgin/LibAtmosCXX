
//
// Implementation of getters
//

uint64_t 
lam::math::AVX512VComplex1D::get_nsize() const {
	return (this->m_nsize);
}

 double *
lam::math::AVX512VComplex1D::getRe() const {
	return (this->m_Re);
}

 double * 
lam::math::AVX512VComplex1D::getIm() const {
	return (this->m_Im);
}

bool
lam::math::AVX512VComplex1D::get_isbuilt() const {
	return (this->m_isbuilt);
}