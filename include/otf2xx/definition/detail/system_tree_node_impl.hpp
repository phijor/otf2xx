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

#ifndef INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SYSTEM_TREE_NODE_HPP
#define INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SYSTEM_TREE_NODE_HPP

#include <otf2xx/exception.hpp>

#include <otf2xx/fwd.hpp>
#include <otf2xx/reference.hpp>

#include <otf2xx/definition/detail/impl_base.hpp>
#include <otf2xx/definition/detail/owning_ptr.hpp>

#include <otf2xx/definition/string.hpp>

namespace otf2
{
namespace definition
{
    namespace detail
    {

        class system_tree_node_impl : public impl_base<system_tree_node_impl>
        {
        public:
            system_tree_node_impl(reference<system_tree_node> ref,
                                  const otf2::definition::string& name,
                                  const otf2::definition::string& class_name,
                                  system_tree_node_impl* parent, std::int64_t retain_count = 0)
            : impl_base(retain_count), ref_(ref), name_(name), class_name_(class_name),
              parent_(parent)
            {
            }

            system_tree_node_impl(reference<system_tree_node> ref,
                                  const otf2::definition::string& name,
                                  const otf2::definition::string& class_name,
                                  std::int64_t retain_count = 0)
            : impl_base(retain_count), ref_(ref), name_(name), class_name_(class_name),
              parent_(nullptr)
            {
            }

            // no implicit copy allowed, see duplicate()
            system_tree_node_impl(const system_tree_node_impl&) = delete;
            system_tree_node_impl& operator=(const system_tree_node_impl&) = delete;

            system_tree_node_impl(system_tree_node_impl&&) = default;
            system_tree_node_impl& operator=(system_tree_node_impl&&) = default;

            static system_tree_node_impl* undefined()
            {
                static system_tree_node_impl undef(otf2::reference<system_tree_node>::undefined(),
                                                   string::undefined(), string::undefined(), 1);
                return &undef;
            }

            reference<system_tree_node> ref() const
            {
                return ref_;
            }

            const otf2::definition::string& name() const
            {
                return name_;
            }

            const otf2::definition::string& class_name() const
            {
                return class_name_;
            }

            bool has_parent() const
            {
                return parent_.get() != nullptr;
            }

            system_tree_node_impl* parent() const
            {
                if (!has_parent())
                {
                    make_exception("The system tree node '", name().str(),
                                   "' hasn't got a parent.");
                }

                return parent_.get();
            }

        private:
            reference<system_tree_node> ref_;
            otf2::definition::string name_;
            otf2::definition::string class_name_;
            owning_ptr<system_tree_node_impl> parent_;
        };
    }
}
} // namespace otf2::definition::detail

#endif // INCLUDE_OTF2XX_DEFINITIONS_DETAIL_SYSTEM_TREE_NODE_HPP
