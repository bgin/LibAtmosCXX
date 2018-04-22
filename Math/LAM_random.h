
#ifndef __LAM_RANDOM_H__
#define __LAM_RANDOM_H__

#if !defined (LAM_RANDOM_MAJOR)
#define LAM_RANDOM_MAJOR 1
#endif

#if !defined (LAM_RANDOM_MINOR)
#define LAM_RANDOM_MINOR 0
#endif

#if !defined (LAM_RANDOM_MICRO)
#define LAM_RANDOM_MICRO 0
#endif

#if !defined (LAM_RANDOM_FULLVER)
#define LAM_RANDOM_FULLVER 1000
#endif

#if !defined (LAM_RANDOM_CREATE_DATE)
#define LAM_RANDOM_CREATE_DATE "19-04-2018 15:57 +00200 (THR 19 APR 2018 GMT+2)"
#endif

#if !defined (LAM_RANDOM_BUILD_DATE)
#define LAM_RANDOM_BUILD_DATE " "
#endif

#if !defined (LAM_RANDOM_AUTHOR)
#define LAM_RANDOM_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_RANDOM_DESCRIPT)
#define LAM_RANDOM_DESCRIPT "Implementation of various statistical random dstribution (based on header random)"
#endif

#include <time.h>
#include <random>
#include <type_traits>
#include <cstdint>
#include "../LAM_error_macros.h"

namespace lam {
	namespace math {
		namespace stat {

			template<
			class Distribution,
			class Engine,
		    typename Value>      struct UniformDistributions {

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				uniform_distribution(_Inout_ Value * __restrict v,
				                _In_ const int64_t vlen,
				                _In_ const Distribution &distr,
				                _In_ Engine &eng) {
						
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_integral<Value>::value,void>::type
				uniform_distribution(_Inout_ Value * __restrict v,
							   _In_ const int64_t vlen,
							   _In_ const Distribution &distr,
							   _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

			 };

			 template<
			 class Distribution,
			 class Engine,
			 typename Value>    struct BernoulliDistributions {
				
				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				bernoulli_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_integral<Value>::value,void>::type
				bernoulli_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				binomial_distribution(_Inout_ Value * __restrict v,
								      _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
									  _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_integral<Value>::value,void>::type
				binomial_distribution(_Inout_ Value * __restrict v,
									  _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
									  _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				geometric_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				geometric_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				neg_binomial_distribution(_Inout_ Value * __restrict v,
										  _In_ const int64_t vlen,
										  _In_ const Distribution &distr,
										  _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_integral<Value>::value,void>::type
				neg_binomial_distribution(_Inout_ Value * __restrict v,
										  _In_ const int64_t vlen,
										  _In_ const Distribution &distr,
										  _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}


			 };


			 template<
			 class Distribution,
			 class Engine,
			 typename Value >		  struct PoissonDistributions {


					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					poisson_distribution(_Inout_ Value * __restrict v,
										 _In_ const int64_t vlen,
										 _In_ const Distribution &distr,
										 _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					poisson_distribution(_Inout_ Value * __restrict v,
										 _In_ const int64_t vlen,
										 _In_ const Distribution &distr,
										 _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					exponential_distribution(_Inout_ Value * __restrict v,
											 _In_ const int64_t vlen,
											 _In_ const Distribution &distr,
										     _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					exponential_distribution(_Inout_ Value * __restrict v,
											 _In_ const int64_t vlen,
											 _In_ const Distribution &distr,
											 _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					gamma_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					gamma_distribution(_Inout_ Value * __restrict v,
									   _In_ const int64_t vlen,
									   _In_ const Distribution &distr,
									   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					weibull_distribution(_Inout_ Value * __restrict v,
										 _In_ const int64_t vlen,
										 _In_ const Distribution &distr,
										 _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					weibull_distribution(_Inout_ Value * __restrict v,
										 _In_ const int64_t vlen,
										 _In_ const Distribution &distr,
										 _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					extreme_value_distribution(_Inout_ Value * __restrict v,
											   _In_ const int64_t vlen,
											   _In_ const Distribution &distr,
											   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					extreme_value_distribution(_Inout_ Value * __restrict v,
											   _In_ const int64_t vlen,
											   _In_ const Distribution &distr,
											   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}
			};

			template<
			class Distribution,
			class Engine,
			typename Value >     struct NormalDistributions {
				
					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					normal_distribution(_Inout_ Value * __restrict v,
										_In_ const int64_t vlen,
										_In_ const Distribution &distr,
										_In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					normal_distribution(_Inout_ Value * __restrict v,
										_In_ const int64_t vlen,
										_In_ const Distribution &distr,
										_In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_floating_point<Value>::value,void>::type
					lognormal_distribution(_Inout_ Value * __restrict v,
										   _In_ const int64_t vlen,
										   _In_ const Distribution &distr,
										   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

					inline static
					typename std::enable_if<std::is_integral<Value>::value,void>::type
					lognormal_distribution(_Inout_ Value * __restrict v,
										   _In_ const int64_t vlen,
										   _In_ const Distribution &distr,
										   _In_ Engine &eng) {
						
						for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
						}
					}

				   inline static
				   typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				   chisquared_distribution(_Inout_ Value * __restrict v,
										   _In_ const int64_ vlen,
										   _In_ const Distribution &distr,
										   _In_ Engine &eng) {
						
					   for (int64_t i = 0LL; i != vlen; ++i) {
						   v[i] = static_cast<Value>(distr(eng));
					   }
				   }

				   inline static
				   typename std::enable_if<std::is_integral<Value>::value, void>::type
				   chisquared_distribution(_Inout_ Value * __restrict v,
										   _In_ const int64_ vlen,
										   _In_ const Distribution &distr,
										   _In_ Engine &eng) {

					   for (int64_t i = 0LL; i != vlen; ++i) {
							   v[i] = static_cast<Value>(distr(eng));
					  }
				 }

				 inline static
				 typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				 cauchy_distribution(_Inout_ Value * __restrict v,
									 _In_ const int64_t vlen,
									 _In_ const Distribution &distr,
									 _In_ Engine &eng) {
						
					 for (int64_t i = 0LL; i != vlen; ++i) {
						 v[i] = static_cast<Value>(distr(eng));
					 }
				 }

				 inline static
				 typename std::enable_if<std::is_integral<Value>::value,void>::type
				 cauchy_distribution(_Inout_ Value * __restrict v,
									 _In_ const int64_t vlen,
									 _In_ const Distribution &distr,
									 _In_ Engine &eng) {
					
					 for (int64_t i = 0LL; i != vlen; ++i) {
						 v[i] = static_cast<Value>(distr(eng));
					 }
				 }

				 inline static
				 typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				 fisherf_distribution(_Inout_ Value * __restrict v,
									  _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
									  _In_ Engine &eng) {
					
					 for (int64_t i = 0LL; i != vlen; ++i) {
						 v[i] = static_cast<Value>(distr(eng));
					 }
				 }

				 inline static
				 typename std::enable_if<std::is_integral<Value>::value, void>::type
				 fisherf_distribution(_Inout_ Value * __restrict v,
									  _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
									  _In_ Engine &eng) {

					 for (int64_t i = 0LL; i != vlen; ++i) {
							 v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_floating_point<Value>::value,void>::type
				studentt_distribution(_Inout_ Value * __restrict v,
									  _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
									  _In_ Engine &eng) {
					
					for (int64_t i = 0LL; i != vlen; ++i) {
						v[i] = static_cast<Value>(distr(eng));
					}
				}

				inline static
				typename std::enable_if<std::is_integral<Value>::value, void>::type
				studentt_distribution(_Inout_ Value * __restrict v,
									  _In_ const int64_t vlen,
									  _In_ const Distribution &distr,
								      _In_ Engine &eng) {

					for (int64_t i = 0LL; i != vlen; ++i) {
							v[i] = static_cast<Value>(distr(eng));
					 }
				 }
			};



			//
			//	Different implementation of random distributions
			//


			enum class RandEngines : unsigned int {

				DEFAULT_RANDOM_ENGINE,
				LINEAR_CONGRUENTIAL_ENGINE,
				MINSTD_RANDOM,
				MINSTD_RANDOM0,
				MT199937,
				MT199937_64,
				RAN_LUX24,
				RAN_LUX48,
				KNUTH_B
			};

			template<typename Value>  struct ImplBernoulliDistribution {
					
				

				template<typename T = Value>
				typename inline static
				std::enable_if<std::is_floating_point<T>::value,void>::type
				bernoulli_distribution(_Inout_ T * __restrict v,
									   _In_ const double prob,
									   _In_  clock_t init_seed,
									   _In_ RandEngines eng) {

					clock_t seed{ clock() };
					init_seed ^= seed;
			switch (eng) {
				case RandEngines::DEFAULT_RANDOM_ENGINE: {
							std::default_random_engine dre{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(dre));
				}
						break;
				case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
							constexpr uint32_t val1 = 56U;
							constexpr uint32_t val2 = 65536U;
							constexpr uint32_t val3 = 2147483647U;
							std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(lce));
				}
					   break;
				case RandEngines::MINSTD_RANDOM: {
						    std::minstd_rand msr{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(msr));
				}
					  break;
				case RandEngines::MINSTD_RANDOM0: {
							std::minstd_rand0 msr0{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t  i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(msr0));
				}
					 break;
				case RandEngines::MT199937: {
							std::mt19937 mt{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(mt));
				}
					 break;
				case RandEngines::MT199937_64: {
							std::mt19937_64 mt64{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(mt64));
				}
					break;
				case RandEngines::RAN_LUX24: {
							std::ranlux24_base rl24base{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(rl24base));
				}
					break;
				case RandEngines::RAN_LUX48: {
							std::ranlux48_base rl48base{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(rl48base));
				}
					break;
				case RandEngines::KNUTH_B: {
							std::knuth_b kb{ init_seed };
							std::bernoulli_distribution bd{prob};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(bd.operator()(kb));

				}
					break;
				default: {
							 PRINT_ERROR_INFO("ImplBernoulliDistribution::bernoulli_distribution -- Invalid Engine value !!!")
							 return;
				     }
				 }
			  }

			};   

			template<typename Value>   struct ImplBinomialDistribution{
				
				

			    template<typename T = Value>
				typename inline static
				std::enable_if<std::is_floating_point<T>::value,void>::type
				binomial_distribution(_Inout_ T * __restrict v,
									  _In_ const T t,
									  _In_ const double prob,
									  _In_ clock_t init_seed,
									  _In_ RandEngines eng) {

					clock_t seed{ clock() };
					init_seed ^= seed;
				switch (eng) {
				  case RandEngines::DEFAULT_RANDOM_ENGINE: {
						std::default_random_engine dre{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(dre));
				       }
					   break;
				  case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
						constexpr uint32_t val1 = 56U;
						constexpr uint32_t val2 = 65536U;
						constexpr uint32_t val3 = 2147483647U;
						std::linear_congruential_engine<T, val1, val2, val3> lce{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(lce));
					 }
					 break;
				  case RandEngines::MINSTD_RANDOM: {
						std::minstd_rand msr{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(msr));
				    }
					   break;
				  case RandEngines::MINSTD_RANDOM0: {
						std::minstd_rand0 msr0{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(msr0));
				   }
				       break;
				  case RandEngines::MT199937: {
						std::mt19937 mt{ init_seed };
						std::binomial_distribution<T,double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(mt));
				  }
				       break;
				  case RandEngines::MT199937_64: {
						std::mt19937_64 mt64{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(mt64));
				  }
					   break;
				  case RandEngines::RAN_LUX24: {
						std::ranlux24 rl24{init_seed};
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(rl24));
				  }
						break;
				  case RandEngines::RAN_LUX48: {
						std::ranlux48 rl48{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(rl48));
				  }
						break;
				  case RandEngines::KNUTH_B: {
						std::knuth_b kb{ init_seed };
						std::binomial_distribution<T, double> bd{t,prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(bd.operator()(kb));
				  }
						break;
				  default: {
							   PRINT_ERROR_INFO("ImplBinomialDistributions::binomial_distribution: -- Invalid switch argument !!!")
							   return;
				  }
				 }

			   }

		   };

		   template<typename Value>    struct ImplGeometricDistribution {

			  
			   
			   template<typename T = Value>
			   typename inline static
			   std::enable_if<std::is_floating_point<T>::value,void>::type
			   geometric_distribution(_Inout_ T * __restrict v,
									  _In_ const double prob,
									  _In_ clock_t init_seed,
									  _In_ RandEngines eng) {
				   clock_t seed{ clock() };
				   init_seed ^= seed;
				switch (eng) {
				    case RandEngines::DEFAULT_RANDOM_ENGINE: {
						std::default_random_engine dre{ init_seed };
						std::geometric_distribution<T, double> gd{prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(gd.operator()(dre));
				   }
				       break;
					case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
					    constexpr uint32_t val1 = 56U;
						constexpr uint32_t val2 = 65536U;
						constexpr uint32_t val3 = 2147483647U;
						std::linear_congruential_engine<T, val1, val2, val3> lce{ init_seed };
						std::geometric_distribution<T, double> gd{prob};
						for (int64_t i = 0LL; i != vlen; ++i)
							v[i] = static_cast<T>(gd.operator()(lce));
					}
					   break;
					case RandEngines::MINSTD_RANDOM: {
						 std::minstd_rand mr{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(mr));
					}
						break;
					case RandEngines::MINSTD_RANDOM0: {
						 std::minstd_rand0 mr0{init_seed};
						 std::geometric_distribution<T, double> gd{ prob };
						 for (int64_t i = 0LL; i != vlen; ++i)
							  v[i] = static_cast<T>(gd.operator()(mr));
						break;
					}
					case RandEngines::MT199937: {
						 std::mt19937 mt{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(mt));
					}
						break;
					case RandEngines::MT199937_64: {
						 std::mt19937_64 mt64{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(mt64));
					}
						break;
					case RandEngines::RAN_LUX24: {
						 std::ranlux24 rl24{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(rl24));
					}
						 break;
					case RandEngines::RAN_LUX48: {
						 std::ranlux48 rl48{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(rl48));
					}
						break;
					case RandEngines::KNUTH_B: {
						 std::knuth_b kb{ init_seed };
						 std::geometric_distribution<T, double> gd{prob};
						 for (int64_t i = 0LL; i != vlen; ++i)
							 v[i] = static_cast<T>(gd.operator()(kb));
					}
						break;
					default: {
								 PRINT_ERROR_INFO("ImplGeometricDistribution::geometric_distribution -- Invalid switch argument !!!")
								 return;
				  	   }
					}
				 }
		     
		    };
		   

			template<typename Value>    struct  ImplPoissonDistribution {
					
				

				template<typename T = Value>
				typename inline static
				std::enable_if<std::is_floating_point<T>::value,void>::type
				poisson_distribution(_Inout_ T * __restrict v,
									 _In_ const int64_t vlen,
									 _In_ const T m,
									 _In_ clock_t init_seed,
									 _In_ RandEngines eng) {

					clock_t seed{ clock() };
					init_seed ^= seed;
					switch (eng) {
					case RandEngines::DEFAULT_RANDOM_ENGINE: {
							std::default_random_engine dre{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(dre));

					    }
						 break;
					case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
							constexpr int32_t val1 = 56U;
							constexpr int32_t val2 = 65536U;
							constexpr int32_t val3 = 2147483647U;
							std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(lce));
					}
					     break;
					case RandEngines::MINSTD_RANDOM: {
							std::minstd_rand msr{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(msr));
					}
						 break;
					case RandEngines::MINSTD_RANDOM0: {
							std::minstd_rand0 msr0{ init_seed };
						    std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(msr0));
					}
						 break;
					case RandEngines::MT199937: {
							std::mt19937 mt{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(mt));
					}
						 break;
					case RandEngines::MT199937_64: {
							std::mt19937_64 mt64{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(mt64));
					}
						 break;
					case RandEngines::RAN_LUX24: {
							std::ranlux24 rl24{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(rl24));
					}
						 break;
					case RandEngines::RAN_LUX48: {
							std::ranlux48 rl48{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(rl48));
					}
						 break;
					case RandEngines::KNUTH_B: {
							std::knuth_b kb{ init_seed };
							std::poisson_distribution<T, double> pd{m};
							for (int64_t i = 0LL; i != vlen; ++i)
								v[i] = static_cast<T>(pd.operator()(kb));
					}
						  break;
					default: {
								 PRINT_ERROR_INFO("ImplPoissonDistribution::poisson_distribution: -- Invalid switch argument !!!")
								 return;
					    }
					}
				}
			};


			template<typename Value>	struct  ImplExponentialDistribution {

				

				template<typename T = Value>
				typename inline static
				std::enable_if<std::is_floating_point<T>::value,void>::type
				exponential_distribution(_Inout_ T * __restrict v,
										 _In_ const int64_t vlen,
										 _In_ const T lambda,
										 _In_ clock_t init_seed,
										 _In_ RandEngines eng) {
					clock_t seed{ clock() };
					init_seed ^= seed;
					switch (eng) {
					  case RandEngines::DEFAULT_RANDOM_ENGINE: {
								std::default_random_engine dre{ init_seed };
								std::exponential_distribution<T> ed{lambda};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(ed.operator()(dre));
					   }
						  break;
					  case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
								constexpr uint32_t val1 = 56U;
								constexpr uint32_t val2 = 65536U;
								constexpr uint32_t val3 = 2147483647U;
								std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
								std::exponential_distribution<T> ed{lambda};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(ed.operator()(lce));
					  }
					     break;
					  case RandEngines::MINSTD_RANDOM: {
								std::minstd_rand msr{ init_seed };
								std::exponential_distribution<T> ed{lambda};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(ed.operator()(msr));
					  }
						 break;
					  case RandEngines::MINSTD_RANDOM0: {
								std::minstd_rand0 msr0{ init_seed };
								std::exponential_distribution<T> ed{lambda};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(ed.operator()(msr0));
					  }
						 break;
					  case RandEngines::MT199937: {
								 std::mt19937 mt{ init_seed };
								 std::exponential_distribution<T> ed{lambda};
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(ed.operator()(mt));
					  }
						break;
					  case RandEngines::MT199937_64: {
								 std::mt19937_64 mt64{ init_seed };
								 std::exponential_distribution<T> ed{lambda};
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(ed.operator()(mt64));
					  }
					    break;
					  case RandEngines::RAN_LUX24: {
								 std::ranlux24 rl24{ init_seed };
								 std::exponential_distribution<T> ed{lambda};
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(ed.operator()(rl24));
					  }
						break;
					  case RandEngines::RAN_LUX48: {
								 std::ranlux48 rl48{ init_seed };
								 std::exponential_distribution<T> ed{lambda};
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(ed.operator()(rl48));
					  }
					    break;
					  case RandEngines::KNUTH_B: {
								 std::knuth_b kb{ init_seed };
								 std::exponential_distribution<T> ed{lambda};
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(ed.operator()(kb));
					  }
					    break;
					  default: {
								   PRINT_ERROR_INFO("ImplExponentialDistribution::exponential_distribution: -- Invalid switch argument !!!")
								   return;
					  }
					}
				}
			};

			template<typename Value>	struct ImplGammaDistributions{
				
				

				template<typename T = Value>
				typename inline static
				std::enable_if<std::is_floating_point<T>::value,void>::type
				gamma_distribution(_Inout_ T * __restrict v,
								  _In_ const int64_t vlen,
								  _In_ const T alfa,
								  _In_ const T beta,
								  _In_ clock_t init_seed,
								  _In_ RandEngines eng) {

					clock_t seed{ clock() };
					init_seed ^= seed;
					switch (eng) {
					case RandEngines::DEFAULT_RANDOM_ENGINE: {
								std::default_random_engine dre{ init_seed };
								std::gamma_distribution<T> gd{alfa,beta};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(gd.operator()(dre));
					   }
					     break;
					case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
								constexpr uint32_t val1 = 56U;
								constexpr uint32_t val2 = 65536U;
								constexpr uint32_t val3 = 2147483647U;
								std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
								std::gamma_distribution<T> gd{alfa,beta};
								for (int64_t i = 0LL; i != vlen; ++i)
									v[i] = static_cast<T>(gd.operator()(dre));
					  }
					     break;
					case RandEngines::MINSTD_RANDOM: {
								 std::minstd_rand msr{init_seed};
								 std::gamma_distribution<T> gd{ alfa, beta };
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(gd.operator()(msr));
					  }
						 break;
					case RandEngines::MINSTD_RANDOM0: {
								 std::minstd_rand0 msr0{init_seed};
								 std::gamma_distribution<T> gd{ alfa, beta };
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(gd.operator()(msr0));
					}
						 break;
					case RandEngines::MT199937: {
								 std::mt19937 mt{init_seed};
								 std::gamma_distribution<T> gd{ alfa, beta };
								 for (init64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(gd.operator()(mt));
					}
						 break;
					case RandEngines::MT199937_64: {
								 std::mt19937_64 mt64{init_seed};
								 std::gamma_distribution<T> gd{ alfa, beta };
								 for (int64_t i = 0LL; i != vlen; ++i)
									 v[i] = static_cast<T>(gd.operator()(mt64));
					}
						  break;
					case RandEngines::RAN_LUX24: {
								  std::ranlux24 rl24{ init_seed };
								  std::gamma_distribution<T> gd{alfa,beta};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(gd.operator()(rl24));
					}
						  break;
					case RandEngines::RAN_LUX48: {
								  std::ranlux48 rl48{ init_seed };
								  std::gamma_distribution<T> gd{alfa,beta};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(gd.operator()(rl48));
					}
						  break;
					case RandEngines::KNUTH_B: {
								  std::knuth_b kb{ init_seed };
								  std::gamma_distribution<T> gd{alfa,beta};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(gd.operator()(kb));
					}
						  break;
					default: {
								 PRINT_ERROR_INFO("ImplGammaDistributions::gamma_distribution: -- Invalid switch argument !!!")
								 return;
					    }
					}
				}
			};

			template<typename Value>   struct ImplNormalDistributions {
				
					template<typename T = Value>
					typename inline static
					std::enable_if<std::is_floating_point<T>::value,void>::type
					normal_distribution(_Inout_ T * __restrict v,
										_In_ const int64_t vlen,
										_In_ const T mikron,
										_In_ const T sigma,
										_In_ clock_t init_seed,
										_In_ RandEngines eng) {

						clock_t seed{ clock() };
						init_seed ^= seed;
						switch (eng) {
						case RandEngines::DEFAULT_RANDOM_ENGINE: {
								  std::default_random_engine dre{ init_seed };
								  std::normal_distribution<T> nd{mikron,sigma};
								  for (int64_t i = 0LL; i != vlen; ++i)
									   v[i] = static_cast<T>(nd.operator()(dre));
						}
							break;
						case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
								  constexpr uint32_t val1 = 56U;
								  constexpr uint32_t val2 = 65536U;
								  constexpr uint32_t val3 = 2147483647U;
								  std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
								  std::normal_distribution<T> nd{mikron,sigma};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(lce));
						}
							break;
						case RandEngines::MINSTD_RANDOM: {
								  std::minstd_rand msr{ init_seed };
								  std::normal_distribution<T> nd{mikron,sigma};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(msr));
						}
							break;
						case RandEngines::MINSTD_RANDOM0: {
								  std::minstd_rand0 msr0{init_seed};
								  std::normal_distribution<T> nd{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(msr0));
						}
							break;
						case RandEngines::MT199937: {
								  std::mt19937 mt{ init_seed };
								  std::normal_distribution<T> nd{mikron,sigma};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(mt));
						}
							break;
						case RandEngines::MT199937_64: {
								  std::mt19937_64 mt64{init_seed};
								  std::normal_distribution<T> nd{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(mt64));
						}
							break;
						case RandEngines::RAN_LUX24: {
								  std::ranlux24 rl24{init_seed};
								  std::normal_distribution<T> nd{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(rl24));
						}
							break;
						case RandEngines::RAN_LUX48: {
								  std::ranlux48 rl48{init_seed};
								  std::normal_distribution<T> nd{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(rl48));
						}
							break;
						case RandEngines::KNUTH_B: {
								  std::knuth_b kb{init_seed};
								  std::normal_distribution<T> nd{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(nd.operator()(kb));
						}
							break;
						default: {
									 PRINT_ERROR_INFO("ImplNormalDistributions::normal_distribution: -- Invalid switch argument!!!")
									 return;
							}
						}
					}
			};

			template<typename Value>	struct ImplLognormalDistributions{
					
					template<typename T = Value>
					typename static inline
					std::enable_if<std::is_floating_point<T>::value,void>::type
					lognormal_distribution(_Inout_ T * __restrict v,
										   _In_ const int64_t vlen,
										   _In_ const T mikron,
										   _In_ const T sigma,
										   _In_ clock_t init_seed,
										   _In_ RandEngines eng) {

						clock_t seed{ clock() };
						init_seed ^= seed;
						switch (eng) {
						case RandEngines::DEFAULT_RANDOM_ENGINE: {
								  std::default_random_engine dre{ init_seed };
								  std::lognormal_distribution<T> ld{mikron,sigma};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(dre));
						}
							break;
						case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
								  constexpr uint32_t val1 = 56U;
								  constexpr uint32_t val2 = 65536U;
								  constexpr uint32_t val3 = 2147483647U;
								  std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{init_seed};
								  std::lognormal_distribution<T> ld{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(lce));
						}
							break;
						case RandEngines::MINSTD_RANDOM: {
								  std::minstd_rand msr{init_seed};
								  std::lognormal_distribution<T> ld{ mikron, sigma };
								  for (int64_t i = 0LL; i != vlen; ++i )
									  v[i] = static_cast<T>(ld.operator()(msr));
						}
							break;
						case RandEngines::MINSTD_RANDOM0: {
								   std::minstd_rand0 msr0{init_seed};
								   std::lognormal_distribution<T> ld{ mikron, sigma };
								   for (int64_t i = 0LL; i != vlen; ++i)
									   v[i] = static_cast<T>(ld.operator()(msr0));
						}
							break;
						case RandEngines::MT199937: {
									std::mt19937 mt{ init_seed };
								    std::lognormal_distribution<T> ld{mikron,sigma};
									for (int64_t i = 0LL; i != vlen; ++i)
										v[i] = static_cast<T>(ld.operator()(mt));
						}
							break;
						case RandEngines::MT199937_64: {
									 std::mt19937_64 mt64{init_seed};
									 std::lognormal_distribution<T> ld{ mikron, sigma };
									 for (int64_t i = 0LL; i != vlen; ++i)
										 v[i] = static_cast<T>(ld.operator()(mt64));
						}
							break;
						case RandEngines::RAN_LUX24: {
									 std::ranlux24 rl24{init_seed};
									 std::lognormal_distribution<T> ld{ mikron, sigma };
									 for (int64_t i = 0LL; i != vlen; ++i)
										 v[i] = static_cast<T>(ld.operator()(rl24));
						}
							break;
						case RandEngines::RAN_LUX48: {
									 std::ranlux48 rl48{init_seed};
									 std::lognormal_distribution<T> ld{ mikron, sigma };
									 for (int64_t i = 0LL; i != vlen; ++i)
										 v[i] = static_cast<T>(ld.operator()(rl48));
						}
							break;
						case RandEngines::KNUTH_B: {
									 std::knuth_b kb{init_seed};
									 std::lognormal_distribution<T> ld{ mikron, sigma };
									 for (int64_t i = 0LL; i != vlen; ++i)
										 v[i] = static_cast<T>(ld.operator()(kb));
						}
							break;
						default: {
									 PRINT_ERROR_INFO("ImplLognormalDistributions::lognormal_distribution: -- Invalid switch statement !!!")
									 return;
							}
						}
					}
			};

			template<typename Value>	struct ImplChiSquaredDistributions{
					
					template<typename T = Value>
					typename static inline 
					std::enable_if<std::is_floating_point<T>::value,void>::type
					chisquared_distribution(_Inout_ T * __restrict v,
											_In_ const int64_t vlen,
											_In_ const T n,
											_In_ clock_t init_seed,
											_In_ RandEngines eng) {

						clock_t seed{ clock() };
						init_seed ^= seed;
						switch (eng) {
						case RandEngines::DEFAULT_RANDOM_ENGINE: {
								  std::default_random_engine dre{ init_seed };
								  std::chi_squared_distribution<T> csd{n};
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(csd.operator()(dre));
							}
								break;
						case RandEngines::LINEAR_CONGRUENTIAL_ENGINE: {
								  constexpr uint32_t val1 = 56U;
								  constexpr uint32_t val2 = 65536U;
								  constexpr uint32_t val3 = 2147483647U;
								  std::linear_congruential_engine<uint32_t, val1, val2, val3> lce{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									   v[i] = static_cast<T>(ld.operator()(lce));
						}
								break;
						case RandEngines::MINSTD_RANDOM: {
								  std::minstd_rand msr{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									   v[i] = static_cast<T>(ld.operator()(msr));
						}
								break;
						case RandEngines::MINSTD_RANDOM0: {
								  std::minstd_rand0 msr0{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(msr0));
						}
								break;
						case RandEngines::MT199937: {
								  std::mt19937 mt{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(mt));
						}
								break;
						case RandEngines::MT199937_64: {
								  std::mt19937_64 mt64{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(mt64));
						}
								break;
						case RandEngines::RAN_LUX24: {
								  std::ranlux24 rl24{ init_seed };
								  std::chi_squared_distribution<T> csd{ n };
								  for (int64_t i = 0LL; i != vlen; ++i)
									   v[i] = static_cast<T>(ld.operator()(rl24));
						}
								break;
						case RandEngines::RAN_LUX48: {
								 std::ranlux48 rl48{ init_seed };
								 std::chi_squared_distribution<T> csd{ n };
								 for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(rl48));
						}
								break;
						case RandEngines::KNUTH_B: {
								 std::knuth_b kb{ init_seed };
								 std::chi_squared_distribution<T> csd{ n };
								 for (int64_t i = 0LL; i != vlen; ++i)
									  v[i] = static_cast<T>(ld.operator()(kb));
						}
								break;
						default: {
									 PRINT_ERROR_INFO("ImplChisquaredDistributions::chisquared_distribution: -- Invalid switch statement !!!")
										 return;
						    }
						
						}
					}
			  };


			
		}
	}
}


#endif /*__LAM_RANDOM_H__*/