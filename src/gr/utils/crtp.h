// Copyright 2014 Nicolas Mellado
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -------------------------------------------------------------------------- //
//
// Authors: Gael Guennebaud

#ifndef _OPENGR_UTILS_CRTP_H_
#define _OPENGR_UTILS_CRTP_H_



namespace gr{
    namespace Utils{

#ifndef PARSED_BY_DOXYGEN
        /// Internal namespace used for crtp implementation
        namespace crtp {
            struct EmptyBaseClass {};

            template</*class Derived,*/
                     template <class> class... Bases>
            struct make_base;

            template</*class Derived,*/
                     template <class> class Base>
            struct make_base<Base> {
                typedef Base<EmptyBaseClass > type;
            };

            template</*class Derived,*/
                     template <class> class... Bases,
                     template <class> class Base0>
            struct make_base<Base0,Bases...> {
                typedef Base0<typename make_base<Bases...>::type> type;
            };
        }
#endif

        /// CRTP class designed by Gael Guennebaud
        /// Source: http://disq.us/p/1tf4a7l
        ///         https://www.onlinegdb.com/rJEhwUc-m
    } // namespace Utils
} // namespace gr

#endif // CRTP_H
