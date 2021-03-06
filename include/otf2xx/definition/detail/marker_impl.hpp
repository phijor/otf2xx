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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_MARKER_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_MARKER_HPP

#include <otf2xx/common.hpp>
#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/impl_base.hpp>

#include <string>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class marker_impl : public impl_base<marker_impl>
        {
        public:
            using severity_type = otf2::common::marker_severity_type;

            marker_impl(otf2::reference<otf2::definition::marker> ref, const std::string& group,
                        const std::string& category, severity_type severity,
                        std::int64_t retain_count = 0)
            : impl_base(retain_count), ref_(ref), group_(group), category_(category),
              severity_(severity)
            {
            }

            // no implicit copy allowed, see duplicate()
            marker_impl(const marker_impl&) = delete;
            marker_impl& operator=(const marker_impl&) = delete;

            marker_impl(marker_impl&&) = default;
            marker_impl& operator=(marker_impl&&) = default;

            static marker_impl* undefined()
            {
                static marker_impl undef(otf2::reference<otf2::definition::marker>::undefined(), "",
                                         "", severity_type::none, 1);
                return &undef;
            }

            const std::string& group() const
            {
                return group_;
            }

            const std::string& category() const
            {
                return category_;
            }

            severity_type severity() const
            {
                return severity_;
            }

            otf2::reference<otf2::definition::marker> ref() const
            {
                return ref_;
            }

        private:
            otf2::reference<otf2::definition::marker> ref_;
            std::string group_;
            std::string category_;
            severity_type severity_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_MARKER_HPP
