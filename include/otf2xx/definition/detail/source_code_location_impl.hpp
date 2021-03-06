/*
 * This file is part of otf2xx (https://github.com/tud-zih-energy/otf2xx)
 * otf2xx - A wrapper for the Open Trace Format 2 library
 *
 * Copyright (c) 2013-2016, Technische Universität Dresden, Germany
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SOURCE_CODE_LOCATION_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SOURCE_CODE_LOCATION_HPP

#include <otf2xx/exception.hpp>

#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/impl_base.hpp>

#include <otf2xx/definition/string.hpp>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class source_code_location_impl : public impl_base<source_code_location_impl>
        {
        public:
            source_code_location_impl(reference<source_code_location> ref,
                                      const otf2::definition::string& file,
                                      std::uint32_t line_number, std::int64_t retain_count = 0)
            : impl_base(retain_count), ref_(ref), file_(file), line_number_(line_number)
            {
            }

            // no implicit copy allowed, see duplicate()
            source_code_location_impl(const source_code_location_impl&) = delete;
            source_code_location_impl& operator=(const source_code_location_impl&) = delete;

            source_code_location_impl(source_code_location_impl&&) = default;
            source_code_location_impl& operator=(source_code_location_impl&&) = default;

            static source_code_location_impl* undefined()
            {
                static source_code_location_impl undef(
                    otf2::reference<source_code_location>::undefined(), string::undefined(), 0, 1);
                return &undef;
            }

            reference<source_code_location> ref() const
            {
                return ref_;
            }

            const otf2::definition::string& file() const
            {
                return file_;
            }

            std::uint32_t line_number() const
            {
                return line_number_;
            }

        private:
            reference<source_code_location> ref_;
            otf2::definition::string file_;
            std::uint32_t line_number_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SOURCE_CODE_LOCATION_HPP
