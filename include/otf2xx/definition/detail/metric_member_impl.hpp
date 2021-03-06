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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_MEMBER_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_MEMBER_HPP

#include <otf2xx/common.hpp>
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

        class metric_member_impl : public impl_base<metric_member_impl>
        {
        public:
            typedef otf2::common::metric_type metric_type;
            typedef otf2::common::metric_mode metric_mode;
            typedef otf2::common::type value_type_type;
            typedef otf2::common::base_type value_base_type;
            typedef std::int64_t value_exponent_type;

            metric_member_impl(reference<metric_member> ref, const otf2::definition::string& name,
                               const otf2::definition::string& description, metric_type type,
                               metric_mode mode, value_type_type value_type,
                               value_base_type value_base, value_exponent_type value_exponent,
                               const otf2::definition::string& value_unit,
                               std::int64_t retain_count = 0)
            : impl_base(retain_count), ref_(ref), name_(name), description_(description),
              type_(type), mode_(mode), value_type_(value_type), value_base_(value_base),
              value_exponent_(value_exponent), value_unit_(value_unit)
            {
            }

            // no implicit copy, see duplicate()
            metric_member_impl(const metric_member_impl&) = delete;
            metric_member_impl& operator=(const metric_member_impl&) = delete;

            metric_member_impl(metric_member_impl&&) = default;
            metric_member_impl& operator=(metric_member_impl&&) = default;

            static metric_member_impl* undefined()
            {
                static metric_member_impl undef(
                    otf2::reference<metric_member>::undefined(),
                    otf2::definition::string::undefined(), otf2::definition::string::undefined(),
                    metric_type::other, metric_mode::absolute_last, value_type_type::none,
                    value_base_type::binary, 0, otf2::definition::string::undefined(), 1);
                return &undef;
            }

            otf2::reference<metric_member> ref() const
            {
                return ref_;
            }

            const otf2::definition::string& name() const
            {
                return name_;
            }

            const otf2::definition::string& description() const
            {
                return description_;
            }

            metric_type type() const
            {
                return type_;
            }

            metric_mode mode() const
            {
                return mode_;
            }

            otf2::common::metric_value_property property() const
            {
                static const int property_mask = 15; // = 000...0001111

                return static_cast<otf2::common::metric_value_property>(static_cast<int>(mode()) &
                                                                        property_mask);
            }

            value_type_type value_type() const
            {
                return value_type_;
            }

            value_base_type value_base() const
            {
                return value_base_;
            }

            value_exponent_type value_exponent() const
            {
                return value_exponent_;
            }

            const otf2::definition::string& value_unit() const
            {
                return value_unit_;
            }

        private:
            reference<metric_member> ref_;
            otf2::definition::string name_;
            otf2::definition::string description_;
            metric_type type_;
            metric_mode mode_;
            value_type_type value_type_;
            value_base_type value_base_;
            value_exponent_type value_exponent_;
            otf2::definition::string value_unit_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_METRIC_MEMBER_HPP
