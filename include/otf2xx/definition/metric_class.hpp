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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_METRIC_CLASS_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_METRIC_CLASS_HPP

#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/base.hpp>
#include <otf2xx/definition/detail/metric_base.hpp>
#include <otf2xx/definition/detail/metric_class_impl.hpp>

namespace otf2
{
namespace definition
{

    /**
     * \brief class for representing metric class definitions
     *
     * A metric class is a collection of metric members.
     *
     * If you don't have a referencing metric instance, then the scope
     * and recorder of this metric is implicitly given by the location,
     * where the referencing metric event occures.
     */
    class metric_class : public detail::base<metric_class>
    {
        typedef detail::base<metric_class> base;
        typedef otf2::traits::definition_impl_type<metric_class>::type impl_type;
        using base::base;

    public:
        typedef impl_type::metric_occurence metric_occurence;
        typedef impl_type::recorder_kind_type recorder_kind_type;

        typedef impl_type::iterator iterator;

        metric_class(reference<detail::metric_base> ref, metric_occurence occurence,
                     recorder_kind_type recorder_kind)
        : base(new impl_type(ref, occurence, recorder_kind))
        {
        }

        metric_class() = default;

        /**
         * \brief returns the number of metric members
         */
        std::size_t size() const
        {
            assert(this->is_valid());
            return this->data_->size();
        }

        /**
         * \brief add a metric member to this metric class
         */
        void add_member(const otf2::definition::metric_member& member)
        {
            assert(this->is_valid());
            this->data_->add_member(member);
        }

        /**
         * \brief the occurence of this metric class
         *
         * \see \ref otf2::common::metric_occurence
         */
        metric_occurence occurence() const
        {
            assert(this->is_valid());
            return this->data_->occurence();
        }

        /**
         * \brief returns the i-th metric member
         */
        const otf2::definition::metric_member& operator[](std::size_t i) const
        {
            assert(this->is_valid());
            return this->data_->operator[](i);
        }

        /**
         * \brief returns the recorder kind of the metric class
         *
         * \see  \ref otf2::common::recorder_kind
         */
        recorder_kind_type recorder_kind() const
        {
            assert(this->is_valid());
            return this->data_->recorder_kind();
        }

        iterator begin() const
        {
            assert(this->is_valid());
            return this->data_->begin();
        }

        iterator end() const
        {
            assert(this->is_valid());
            return this->data_->end();
        }
    };
}
} // namespace otf2::definition

#endif // INCLUDE_OTF2XX_DEFINITIONS_METRIC_CLASS_HPP
