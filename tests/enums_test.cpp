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

#include <otf2xx/common.hpp>

#include <otf2/OTF2_Definitions.h>
#include <otf2/OTF2_Events.h>
#include <otf2/OTF2_GeneralDefinitions.h>
#include <otf2/OTF2_Marker.h>

#include <cassert>

using namespace otf2::common;

/**
 * @brief: Checks the OTF2 and OTF2xx enums and definitions to be equal This test is VERY!
 * important.
 *
 * \warning { If this test fails, expect all input readed from traces to be wrong.
 * Also expect all output traces to be wrong! Fix the problem first. Seriously! }
 *
 */
int main()
{

    static_assert(sizeof(type) == sizeof(OTF2_Type), "Enum size mismatch");
    assert(static_cast<int>(type::none) == OTF2_TYPE_NONE);
    assert(static_cast<int>(type::uint8) == OTF2_TYPE_UINT8);
    assert(static_cast<int>(type::uint16) == OTF2_TYPE_UINT16);
    assert(static_cast<int>(type::uint32) == OTF2_TYPE_UINT32);
    assert(static_cast<int>(type::uint64) == OTF2_TYPE_UINT64);
    assert(static_cast<int>(type::int8) == OTF2_TYPE_INT8);
    assert(static_cast<int>(type::int16) == OTF2_TYPE_INT16);
    assert(static_cast<int>(type::int32) == OTF2_TYPE_INT32);
    assert(static_cast<int>(type::int64) == OTF2_TYPE_INT64);
    assert(static_cast<int>(type::Float) == OTF2_TYPE_FLOAT);
    assert(static_cast<int>(type::Double) == OTF2_TYPE_DOUBLE);
    assert(static_cast<int>(type::string) == OTF2_TYPE_STRING);
    assert(static_cast<int>(type::attribute) == OTF2_TYPE_ATTRIBUTE);
    assert(static_cast<int>(type::location) == OTF2_TYPE_LOCATION);
    assert(static_cast<int>(type::region) == OTF2_TYPE_REGION);
    assert(static_cast<int>(type::group) == OTF2_TYPE_GROUP);
    assert(static_cast<int>(type::metric) == OTF2_TYPE_METRIC);
    assert(static_cast<int>(type::comm) == OTF2_TYPE_COMM);
    assert(static_cast<int>(type::parameter) == OTF2_TYPE_PARAMETER);
    assert(static_cast<int>(type::rma_win) == OTF2_TYPE_RMA_WIN);
    assert(static_cast<int>(type::source_code_location) == OTF2_TYPE_SOURCE_CODE_LOCATION);
    assert(static_cast<int>(type::calling_context) == OTF2_TYPE_CALLING_CONTEXT);
    assert(static_cast<int>(type::interrupt_generator) == OTF2_TYPE_INTERRUPT_GENERATOR);
    assert(static_cast<int>(type::io_file) == OTF2_TYPE_IO_FILE);
    assert(static_cast<int>(type::io_handle) == OTF2_TYPE_IO_HANDLE);

    static_assert(sizeof(group_type) == sizeof(OTF2_GroupType), "Enum size mismatch");
    assert(static_cast<int>(group_type::unknown) == OTF2_GROUP_TYPE_UNKNOWN);
    assert(static_cast<int>(group_type::locations) == OTF2_GROUP_TYPE_LOCATIONS);
    assert(static_cast<int>(group_type::regions) == OTF2_GROUP_TYPE_REGIONS);
    assert(static_cast<int>(group_type::metric) == OTF2_GROUP_TYPE_METRIC);
    assert(static_cast<int>(group_type::comm_locations) == OTF2_GROUP_TYPE_COMM_LOCATIONS);
    assert(static_cast<int>(group_type::comm_group) == OTF2_GROUP_TYPE_COMM_GROUP);
    assert(static_cast<int>(group_type::comm_self) == OTF2_GROUP_TYPE_COMM_SELF);

    static_assert(sizeof(group_flag_type) == sizeof(OTF2_GroupFlag), "Enum size mismatch");
    assert(static_cast<int>(group_flag_type::none) == OTF2_GROUP_FLAG_NONE);
    assert(static_cast<int>(group_flag_type::global_members) == OTF2_GROUP_FLAG_GLOBAL_MEMBERS);

    static_assert(sizeof(location_type) == sizeof(OTF2_LocationType), "Enum size mismatch");
    assert(static_cast<int>(location_type::unknown) == OTF2_LOCATION_TYPE_UNKNOWN);
    assert(static_cast<int>(location_type::cpu_thread) == OTF2_LOCATION_TYPE_CPU_THREAD);
    assert(static_cast<int>(location_type::gpu) == OTF2_LOCATION_TYPE_GPU);
    assert(static_cast<int>(location_type::metric) == OTF2_LOCATION_TYPE_METRIC);

    static_assert(sizeof(parameter_type) == sizeof(OTF2_ParameterType), "Enum size mismatch");
    assert(static_cast<int>(parameter_type::string) == OTF2_PARAMETER_TYPE_STRING);
    assert(static_cast<int>(parameter_type::int64) == OTF2_PARAMETER_TYPE_INT64);
    assert(static_cast<int>(parameter_type::uint64) == OTF2_PARAMETER_TYPE_UINT64);

    static_assert(sizeof(location_group_type) == sizeof(OTF2_LocationGroupType),
                  "Enum size mismatch");
    assert(static_cast<int>(location_group_type::unknown) == OTF2_LOCATION_GROUP_TYPE_UNKNOWN);
    assert(static_cast<int>(location_group_type::process) == OTF2_LOCATION_GROUP_TYPE_PROCESS);

    static_assert(sizeof(role_type) == sizeof(OTF2_RegionRole), "Enum size mismatch");
    assert(static_cast<int>(role_type::unknown) == OTF2_REGION_ROLE_UNKNOWN);
    assert(static_cast<int>(role_type::function) == OTF2_REGION_ROLE_FUNCTION);
    assert(static_cast<int>(role_type::wrapper) == OTF2_REGION_ROLE_WRAPPER);
    assert(static_cast<int>(role_type::loop) == OTF2_REGION_ROLE_LOOP);
    assert(static_cast<int>(role_type::code) == OTF2_REGION_ROLE_CODE);
    assert(static_cast<int>(role_type::parallel) == OTF2_REGION_ROLE_PARALLEL);
    assert(static_cast<int>(role_type::sections) == OTF2_REGION_ROLE_SECTIONS);
    assert(static_cast<int>(role_type::section) == OTF2_REGION_ROLE_SECTION);
    assert(static_cast<int>(role_type::workshare) == OTF2_REGION_ROLE_WORKSHARE);
    assert(static_cast<int>(role_type::single) == OTF2_REGION_ROLE_SINGLE);
    assert(static_cast<int>(role_type::single_sblock) == OTF2_REGION_ROLE_SINGLE_SBLOCK);
    assert(static_cast<int>(role_type::master) == OTF2_REGION_ROLE_MASTER);
    assert(static_cast<int>(role_type::critical) == OTF2_REGION_ROLE_CRITICAL);
    assert(static_cast<int>(role_type::critical_sblock) == OTF2_REGION_ROLE_CRITICAL_SBLOCK);
    assert(static_cast<int>(role_type::master) == OTF2_REGION_ROLE_MASTER);
    assert(static_cast<int>(role_type::critical) == OTF2_REGION_ROLE_CRITICAL);
    assert(static_cast<int>(role_type::critical_sblock) == OTF2_REGION_ROLE_CRITICAL_SBLOCK);
    assert(static_cast<int>(role_type::atomic) == OTF2_REGION_ROLE_ATOMIC);
    assert(static_cast<int>(role_type::barrier) == OTF2_REGION_ROLE_BARRIER);
    assert(static_cast<int>(role_type::implicit_barrier) == OTF2_REGION_ROLE_IMPLICIT_BARRIER);
    assert(static_cast<int>(role_type::flush) == OTF2_REGION_ROLE_FLUSH);
    assert(static_cast<int>(role_type::ordered) == OTF2_REGION_ROLE_ORDERED);
    assert(static_cast<int>(role_type::ordered_sblock) == OTF2_REGION_ROLE_ORDERED_SBLOCK);
    assert(static_cast<int>(role_type::task) == OTF2_REGION_ROLE_TASK);
    assert(static_cast<int>(role_type::task_create) == OTF2_REGION_ROLE_TASK_CREATE);
    assert(static_cast<int>(role_type::task_wait) == OTF2_REGION_ROLE_TASK_WAIT);
    assert(static_cast<int>(role_type::coll_one2all) == OTF2_REGION_ROLE_COLL_ONE2ALL);
    assert(static_cast<int>(role_type::coll_all2one) == OTF2_REGION_ROLE_COLL_ALL2ONE);
    assert(static_cast<int>(role_type::coll_all2all) == OTF2_REGION_ROLE_COLL_ALL2ALL);
    assert(static_cast<int>(role_type::coll_other) == OTF2_REGION_ROLE_COLL_OTHER);
    assert(static_cast<int>(role_type::file_io) == OTF2_REGION_ROLE_FILE_IO);
    assert(static_cast<int>(role_type::point2point) == OTF2_REGION_ROLE_POINT2POINT);
    assert(static_cast<int>(role_type::rma) == OTF2_REGION_ROLE_RMA);
    assert(static_cast<int>(role_type::data_transfer) == OTF2_REGION_ROLE_DATA_TRANSFER);
    assert(static_cast<int>(role_type::artifical) == OTF2_REGION_ROLE_ARTIFICIAL);
    assert(static_cast<int>(role_type::thread_create) == OTF2_REGION_ROLE_THREAD_CREATE);
    assert(static_cast<int>(role_type::thread_wait) == OTF2_REGION_ROLE_THREAD_WAIT);
    assert(static_cast<int>(role_type::task_untied) == OTF2_REGION_ROLE_TASK_UNTIED);
    assert(static_cast<int>(role_type::allocate) == OTF2_REGION_ROLE_ALLOCATE);
    assert(static_cast<int>(role_type::deallocate) == OTF2_REGION_ROLE_DEALLOCATE);
    assert(static_cast<int>(role_type::reallocate) == OTF2_REGION_ROLE_REALLOCATE);
    assert(static_cast<int>(role_type::file_io_metadata) == OTF2_REGION_ROLE_FILE_IO_METADATA);

    static_assert(sizeof(parameter_type) == sizeof(OTF2_ParameterType), "Enum size mismatch");
    assert(static_cast<int>(paradigm_type::unknown) == OTF2_PARADIGM_UNKNOWN);
    assert(static_cast<int>(paradigm_type::user) == OTF2_PARADIGM_USER);
    assert(static_cast<int>(paradigm_type::compiler) == OTF2_PARADIGM_COMPILER);
    assert(static_cast<int>(paradigm_type::openmp) == OTF2_PARADIGM_OPENMP);
    assert(static_cast<int>(paradigm_type::mpi) == OTF2_PARADIGM_MPI);
    assert(static_cast<int>(paradigm_type::cuda) == OTF2_PARADIGM_CUDA);
    assert(static_cast<int>(paradigm_type::measurement_system) == OTF2_PARADIGM_MEASUREMENT_SYSTEM);
    assert(static_cast<int>(paradigm_type::pthread) == OTF2_PARADIGM_PTHREAD);
    assert(static_cast<int>(paradigm_type::hmpp) == OTF2_PARADIGM_HMPP);
    assert(static_cast<int>(paradigm_type::ompss) == OTF2_PARADIGM_OMPSS);
    assert(static_cast<int>(paradigm_type::hardware) == OTF2_PARADIGM_HARDWARE);
    assert(static_cast<int>(paradigm_type::gaspi) == OTF2_PARADIGM_GASPI);
    assert(static_cast<int>(paradigm_type::upc) == OTF2_PARADIGM_UPC);
    assert(static_cast<int>(paradigm_type::shmem) == OTF2_PARADIGM_SHMEM);
    assert(static_cast<int>(paradigm_type::winthread) == OTF2_PARADIGM_WINTHREAD);
    assert(static_cast<int>(paradigm_type::qtthread) == OTF2_PARADIGM_QTTHREAD);
    assert(static_cast<int>(paradigm_type::acethread) == OTF2_PARADIGM_ACETHREAD);
    assert(static_cast<int>(paradigm_type::tbbthread) == OTF2_PARADIGM_TBBTHREAD);
    assert(static_cast<int>(paradigm_type::openacc) == OTF2_PARADIGM_OPENACC);
    assert(static_cast<int>(paradigm_type::opencl) == OTF2_PARADIGM_OPENCL);
    assert(static_cast<int>(paradigm_type::mtapi) == OTF2_PARADIGM_MTAPI);
    assert(static_cast<int>(paradigm_type::sampling) == OTF2_PARADIGM_SAMPLING);
    assert(static_cast<int>(paradigm_type::none) == OTF2_PARADIGM_NONE);

    static_assert(sizeof(paradigm_class_type) == sizeof(OTF2_ParadigmClass), "Enum size mismatch");
    assert(static_cast<int>(paradigm_class_type::process) == OTF2_PARADIGM_CLASS_PROCESS);
    assert(static_cast<int>(paradigm_class_type::thread_fork_join) ==
           OTF2_PARADIGM_CLASS_THREAD_FORK_JOIN);
    assert(static_cast<int>(paradigm_class_type::thread_create_wait) ==
           OTF2_PARADIGM_CLASS_THREAD_CREATE_WAIT);
    assert(static_cast<int>(paradigm_class_type::accelerator) == OTF2_PARADIGM_CLASS_ACCELERATOR);

    static_assert(sizeof(paradigm_property_type) == sizeof(OTF2_ParadigmProperty),
                  "Enum size mismatch");
    assert(static_cast<int>(paradigm_property_type::comm_name_template) ==
           OTF2_PARADIGM_PROPERTY_COMM_NAME_TEMPLATE);
    assert(static_cast<int>(paradigm_property_type::rma_win_name_template) ==
           OTF2_PARADIGM_PROPERTY_RMA_WIN_NAME_TEMPLATE);
    assert(static_cast<int>(paradigm_property_type::rma_only) == OTF2_PARADIGM_PROPERTY_RMA_ONLY);

    static_assert(sizeof(flags_type) == sizeof(OTF2_RegionFlag), "Enum size mismatch");
    assert(static_cast<int>(flags_type::none) == OTF2_REGION_FLAG_NONE);
    assert(static_cast<int>(flags_type::dynamic) == OTF2_REGION_FLAG_DYNAMIC);
    assert(static_cast<int>(flags_type::phase) == OTF2_REGION_FLAG_PHASE);

    static_assert(sizeof(collective_type) == sizeof(OTF2_CollectiveOp), "Enum size mismatch");
    assert(static_cast<int>(collective_type::barrier) == OTF2_COLLECTIVE_OP_BARRIER);
    assert(static_cast<int>(collective_type::broadcast) == OTF2_COLLECTIVE_OP_BCAST);
    assert(static_cast<int>(collective_type::gather) == OTF2_COLLECTIVE_OP_GATHER);
    assert(static_cast<int>(collective_type::gatherv) == OTF2_COLLECTIVE_OP_GATHERV);
    assert(static_cast<int>(collective_type::scatter) == OTF2_COLLECTIVE_OP_SCATTER);
    assert(static_cast<int>(collective_type::scatterv) == OTF2_COLLECTIVE_OP_SCATTERV);
    assert(static_cast<int>(collective_type::all_gather) == OTF2_COLLECTIVE_OP_ALLGATHER);
    assert(static_cast<int>(collective_type::all_gatherv) == OTF2_COLLECTIVE_OP_ALLGATHERV);
    assert(static_cast<int>(collective_type::all_to_all) == OTF2_COLLECTIVE_OP_ALLTOALL);
    assert(static_cast<int>(collective_type::all_to_allv) == OTF2_COLLECTIVE_OP_ALLTOALLV);
    assert(static_cast<int>(collective_type::all_to_allw) == OTF2_COLLECTIVE_OP_ALLTOALLW);
    assert(static_cast<int>(collective_type::all_reduce) == OTF2_COLLECTIVE_OP_ALLREDUCE);
    assert(static_cast<int>(collective_type::reduce) == OTF2_COLLECTIVE_OP_REDUCE);
    assert(static_cast<int>(collective_type::reduce_scatter) == OTF2_COLLECTIVE_OP_REDUCE_SCATTER);
    assert(static_cast<int>(collective_type::scan) == OTF2_COLLECTIVE_OP_SCAN);
    assert(static_cast<int>(collective_type::exscan) == OTF2_COLLECTIVE_OP_EXSCAN);
    assert(static_cast<int>(collective_type::reduce_scatter_block) ==
           OTF2_COLLECTIVE_OP_REDUCE_SCATTER_BLOCK);
    assert(static_cast<int>(collective_type::create_handle) == OTF2_COLLECTIVE_OP_CREATE_HANDLE);
    assert(static_cast<int>(collective_type::destroy_handle) == OTF2_COLLECTIVE_OP_DESTROY_HANDLE);
    assert(static_cast<int>(collective_type::allocate) == OTF2_COLLECTIVE_OP_ALLOCATE);
    assert(static_cast<int>(collective_type::deallocate) == OTF2_COLLECTIVE_OP_DEALLOCATE);
    assert(static_cast<int>(collective_type::create_handle_and_allocate) ==
           OTF2_COLLECTIVE_OP_CREATE_HANDLE_AND_ALLOCATE);
    assert(static_cast<int>(collective_type::destroy_handle_and_deallocate) ==
           OTF2_COLLECTIVE_OP_DESTROY_HANDLE_AND_DEALLOCATE);

    static_assert(sizeof(metric_type) == sizeof(OTF2_MetricType), "Enum size mismatch");
    assert(static_cast<int>(metric_type::other) == OTF2_METRIC_TYPE_OTHER);
    assert(static_cast<int>(metric_type::papi) == OTF2_METRIC_TYPE_PAPI);
    assert(static_cast<int>(metric_type::rusage) == OTF2_METRIC_TYPE_RUSAGE);
    assert(static_cast<int>(metric_type::user) == OTF2_METRIC_TYPE_USER);

    static_assert(sizeof(metric_timing) == sizeof(OTF2_MetricTiming), "Enum size mismatch");
    assert(static_cast<int>(metric_timing::start) == OTF2_METRIC_TIMING_START);
    assert(static_cast<int>(metric_timing::point) == OTF2_METRIC_TIMING_POINT);
    assert(static_cast<int>(metric_timing::last) == OTF2_METRIC_TIMING_LAST);
    assert(static_cast<int>(metric_timing::next) == OTF2_METRIC_TIMING_NEXT);

    static_assert(sizeof(metric_occurence) == sizeof(OTF2_MetricOccurrence), "Enum size mismatch");
    assert(static_cast<int>(metric_occurence::strict) == OTF2_METRIC_SYNCHRONOUS_STRICT);
    assert(static_cast<int>(metric_occurence::sync) == OTF2_METRIC_SYNCHRONOUS);
    assert(static_cast<int>(metric_occurence::async) == OTF2_METRIC_ASYNCHRONOUS);

    static_assert(sizeof(metric_scope) == sizeof(OTF2_MetricScope), "Enum size mismatch");
    assert(static_cast<int>(metric_scope::location) == OTF2_SCOPE_LOCATION);
    assert(static_cast<int>(metric_scope::location_group) == OTF2_SCOPE_LOCATION_GROUP);
    assert(static_cast<int>(metric_scope::system_tree_node) == OTF2_SCOPE_SYSTEM_TREE_NODE);
    assert(static_cast<int>(metric_scope::group) == OTF2_SCOPE_GROUP);

    static_assert(sizeof(metric_value_property) == sizeof(OTF2_MetricValueProperty),
                  "Enum size mismatch");
    assert(static_cast<int>(metric_value_property::accumulated) == OTF2_METRIC_VALUE_ACCUMULATED);
    assert(static_cast<int>(metric_value_property::absolute) == OTF2_METRIC_VALUE_ABSOLUTE);
    assert(static_cast<int>(metric_value_property::relative) == OTF2_METRIC_VALUE_RELATIVE);

    static_assert(sizeof(base_type) == sizeof(OTF2_Base), "Enum size mismatch");
    assert(static_cast<int>(base_type::binary) == OTF2_BASE_BINARY);
    assert(static_cast<int>(base_type::decimal) == OTF2_BASE_DECIMAL);

    static_assert(sizeof(metric_mode) == sizeof(OTF2_MetricMode), "Enum size mismatch");
    assert(static_cast<int>(metric_mode::accumulated_start) == OTF2_METRIC_ACCUMULATED_START);
    assert(static_cast<int>(metric_mode::accumulated_point) == OTF2_METRIC_ACCUMULATED_POINT);
    assert(static_cast<int>(metric_mode::accumulated_last) == OTF2_METRIC_ACCUMULATED_LAST);
    assert(static_cast<int>(metric_mode::accumulated_next) == OTF2_METRIC_ACCUMULATED_NEXT);
    assert(static_cast<int>(metric_mode::absolute_point) == OTF2_METRIC_ABSOLUTE_POINT);
    assert(static_cast<int>(metric_mode::absolute_last) == OTF2_METRIC_ABSOLUTE_LAST);
    assert(static_cast<int>(metric_mode::absolute_next) == OTF2_METRIC_ABSOLUTE_NEXT);
    assert(static_cast<int>(metric_mode::relative_point) == OTF2_METRIC_RELATIVE_POINT);
    assert(static_cast<int>(metric_mode::relative_last) == OTF2_METRIC_RELATIVE_LAST);
    assert(static_cast<int>(metric_mode::relative_next) == OTF2_METRIC_RELATIVE_NEXT);

    static_assert(sizeof(system_tree_node_domain) == sizeof(OTF2_SystemTreeDomain),
                  "Enum size mismatch");
    assert(static_cast<int>(system_tree_node_domain::machine) == OTF2_SYSTEM_TREE_DOMAIN_MACHINE);
    assert(static_cast<int>(system_tree_node_domain::shared_memory) ==
           OTF2_SYSTEM_TREE_DOMAIN_SHARED_MEMORY);
    assert(static_cast<int>(system_tree_node_domain::numa) == OTF2_SYSTEM_TREE_DOMAIN_NUMA);
    assert(static_cast<int>(system_tree_node_domain::socket) == OTF2_SYSTEM_TREE_DOMAIN_SOCKET);
    assert(static_cast<int>(system_tree_node_domain::cache) == OTF2_SYSTEM_TREE_DOMAIN_CACHE);
    assert(static_cast<int>(system_tree_node_domain::core) == OTF2_SYSTEM_TREE_DOMAIN_CORE);
    assert(static_cast<int>(system_tree_node_domain::pu) == OTF2_SYSTEM_TREE_DOMAIN_PU);

    static_assert(sizeof(interrupt_generator_mode_type) == sizeof(OTF2_InterruptGeneratorMode),
                  "Enum size mismatch");
    assert(static_cast<int>(interrupt_generator_mode_type::time) ==
           OTF2_INTERRUPT_GENERATOR_MODE_TIME);
    assert(static_cast<int>(interrupt_generator_mode_type::count) ==
           OTF2_INTERRUPT_GENERATOR_MODE_COUNT);

    static_assert(sizeof(io_paradigm_class_type) == sizeof(OTF2_IoParadigmClass),
                  "Enum size mismatch");
    assert(static_cast<int>(io_paradigm_class_type::serial) == OTF2_IO_PARADIGM_CLASS_SERIAL);
    assert(static_cast<int>(io_paradigm_class_type::parallel) == OTF2_IO_PARADIGM_CLASS_PARALLEL);

    static_assert(sizeof(io_paradigm_flag_type) == sizeof(OTF2_IoParadigmFlag),
                  "Enum size mismatch");
    assert(static_cast<int>(io_paradigm_flag_type::none) == OTF2_IO_PARADIGM_FLAG_NONE);
    assert(static_cast<int>(io_paradigm_flag_type::os) == OTF2_IO_PARADIGM_FLAG_OS);

    static_assert(sizeof(io_access_mode_type) == sizeof(OTF2_IoAccessMode), "Enum size mismatch");
    assert(static_cast<int>(io_access_mode_type::read_only) == OTF2_IO_ACCESS_MODE_READ_ONLY);
    assert(static_cast<int>(io_access_mode_type::write_only) == OTF2_IO_ACCESS_MODE_WRITE_ONLY);
    assert(static_cast<int>(io_access_mode_type::read_write) == OTF2_IO_ACCESS_MODE_READ_WRITE);
    assert(static_cast<int>(io_access_mode_type::execute_only) == OTF2_IO_ACCESS_MODE_EXECUTE_ONLY);
    assert(static_cast<int>(io_access_mode_type::search_only) == OTF2_IO_ACCESS_MODE_SEARCH_ONLY);

    static_assert(sizeof(io_creation_flag_type) == sizeof(OTF2_IoCreationFlag),
                  "Enum size mismatch");
    assert(static_cast<int>(io_creation_flag_type::none) == OTF2_IO_CREATION_FLAG_NONE);
    assert(static_cast<int>(io_creation_flag_type::create) == OTF2_IO_CREATION_FLAG_CREATE);
    assert(static_cast<int>(io_creation_flag_type::truncate) == OTF2_IO_CREATION_FLAG_TRUNCATE);
    assert(static_cast<int>(io_creation_flag_type::directory) == OTF2_IO_CREATION_FLAG_DIRECTORY);
    assert(static_cast<int>(io_creation_flag_type::exclusive) == OTF2_IO_CREATION_FLAG_EXCLUSIVE);
    assert(static_cast<int>(io_creation_flag_type::no_controlling_terminal) ==
           OTF2_IO_CREATION_FLAG_NO_CONTROLLING_TERMINAL);
    assert(static_cast<int>(io_creation_flag_type::no_follow) == OTF2_IO_CREATION_FLAG_NO_FOLLOW);
    assert(static_cast<int>(io_creation_flag_type::path) == OTF2_IO_CREATION_FLAG_PATH);
    assert(static_cast<int>(io_creation_flag_type::temporary_file) ==
           OTF2_IO_CREATION_FLAG_TEMPORARY_FILE);
    assert(static_cast<int>(io_creation_flag_type::largefile) == OTF2_IO_CREATION_FLAG_LARGEFILE);
    assert(static_cast<int>(io_creation_flag_type::no_seek) == OTF2_IO_CREATION_FLAG_NO_SEEK);
    assert(static_cast<int>(io_creation_flag_type::unique) == OTF2_IO_CREATION_FLAG_UNIQUE);

    static_assert(sizeof(io_status_flag_type) == sizeof(OTF2_IoStatusFlag), "Enum size mismatch");
    assert(static_cast<int>(io_status_flag_type::none) == OTF2_IO_STATUS_FLAG_NONE);
    assert(static_cast<int>(io_status_flag_type::close_on_exec) ==
           OTF2_IO_STATUS_FLAG_CLOSE_ON_EXEC);
    assert(static_cast<int>(io_status_flag_type::append) == OTF2_IO_STATUS_FLAG_APPEND);
    assert(static_cast<int>(io_status_flag_type::non_blocking) == OTF2_IO_STATUS_FLAG_NON_BLOCKING);
    assert(static_cast<int>(io_status_flag_type::async) == OTF2_IO_STATUS_FLAG_ASYNC);
    assert(static_cast<int>(io_status_flag_type::data_sync) == OTF2_IO_STATUS_FLAG_DATA_SYNC);
    assert(static_cast<int>(io_status_flag_type::avoid_caching) ==
           OTF2_IO_STATUS_FLAG_AVOID_CACHING);
    assert(static_cast<int>(io_status_flag_type::no_access_time) ==
           OTF2_IO_STATUS_FLAG_NO_ACCESS_TIME);
    assert(static_cast<int>(io_status_flag_type::delete_on_close) ==
           OTF2_IO_STATUS_FLAG_DELETE_ON_CLOSE);

    static_assert(sizeof(io_seek_option_type) == sizeof(OTF2_IoSeekOption), "Enum size mismatch");
    assert(static_cast<int>(io_seek_option_type::from_start) == OTF2_IO_SEEK_FROM_START);
    assert(static_cast<int>(io_seek_option_type::from_current) == OTF2_IO_SEEK_FROM_CURRENT);
    assert(static_cast<int>(io_seek_option_type::from_end) == OTF2_IO_SEEK_FROM_END);
    assert(static_cast<int>(io_seek_option_type::data) == OTF2_IO_SEEK_DATA);
    assert(static_cast<int>(io_seek_option_type::hole) == OTF2_IO_SEEK_HOLE);

    static_assert(sizeof(io_operation_mode_type) == sizeof(OTF2_IoOperationMode),
                  "Enum size mismatch");
    assert(static_cast<int>(io_operation_mode_type::read) == OTF2_IO_OPERATION_MODE_READ);
    assert(static_cast<int>(io_operation_mode_type::write) == OTF2_IO_OPERATION_MODE_WRITE);
    assert(static_cast<int>(io_operation_mode_type::flush) == OTF2_IO_OPERATION_MODE_FLUSH);

    static_assert(sizeof(io_operation_flag_type) == sizeof(OTF2_IoOperationFlag),
                  "Enum size mismatch");
    assert(static_cast<int>(io_operation_flag_type::none) == OTF2_IO_OPERATION_FLAG_NONE);
    assert(static_cast<int>(io_operation_flag_type::non_blocking) ==
           OTF2_IO_OPERATION_FLAG_NON_BLOCKING);
    assert(static_cast<int>(io_operation_flag_type::collective) ==
           OTF2_IO_OPERATION_FLAG_COLLECTIVE);

    static_assert(sizeof(io_handle_flag_type) == sizeof(OTF2_IoHandleFlag), "Enum size mismatch");
    assert(static_cast<int>(io_handle_flag_type::none) == OTF2_IO_HANDLE_FLAG_NONE);
    assert(static_cast<int>(io_handle_flag_type::pre_created) == OTF2_IO_HANDLE_FLAG_PRE_CREATED);
    assert(static_cast<int>(io_handle_flag_type::all_proxy) == OTF2_IO_HANDLE_FLAG_ALL_PROXY);

    static_assert(sizeof(io_paradigm_property_type) == sizeof(OTF2_IoParadigmProperty),
                  "Enum size mismatch");
    assert(static_cast<int>(io_paradigm_property_type::version) ==
           OTF2_IO_PARADIGM_PROPERTY_VERSION);

    static_assert(sizeof(mapping_type_type) == sizeof(OTF2_MappingType), "Enum size mismatch");
    assert(static_cast<int>(mapping_type_type::string) == OTF2_MAPPING_STRING);
    assert(static_cast<int>(mapping_type_type::attribute) == OTF2_MAPPING_ATTRIBUTE);
    assert(static_cast<int>(mapping_type_type::location) == OTF2_MAPPING_LOCATION);
    assert(static_cast<int>(mapping_type_type::region) == OTF2_MAPPING_REGION);
    assert(static_cast<int>(mapping_type_type::group) == OTF2_MAPPING_GROUP);
    assert(static_cast<int>(mapping_type_type::metric) == OTF2_MAPPING_METRIC);
    assert(static_cast<int>(mapping_type_type::comm) == OTF2_MAPPING_COMM);
    assert(static_cast<int>(mapping_type_type::parameter) == OTF2_MAPPING_PARAMETER);
    assert(static_cast<int>(mapping_type_type::rma_win) == OTF2_MAPPING_RMA_WIN);
    assert(static_cast<int>(mapping_type_type::source_code_location) ==
           OTF2_MAPPING_SOURCE_CODE_LOCATION);
    assert(static_cast<int>(mapping_type_type::calling_context) == OTF2_MAPPING_CALLING_CONTEXT);
    assert(static_cast<int>(mapping_type_type::interrupt_generator) ==
           OTF2_MAPPING_INTERRUPT_GENERATOR);
    assert(static_cast<int>(mapping_type_type::io_file) == OTF2_MAPPING_IO_FILE);
    assert(static_cast<int>(mapping_type_type::io_handle) == OTF2_MAPPING_IO_HANDLE);
    assert(static_cast<int>(mapping_type_type::max) == OTF2_MAPPING_MAX);

    static_assert(sizeof(marker_severity_type) == sizeof(OTF2_MarkerSeverity),
                  "Enum size mismatch");
    assert(static_cast<int>(marker_severity_type::none) == OTF2_SEVERITY_NONE);
    assert(static_cast<int>(marker_severity_type::low) == OTF2_SEVERITY_LOW);
    assert(static_cast<int>(marker_severity_type::medium) == OTF2_SEVERITY_MEDIUM);
    assert(static_cast<int>(marker_severity_type::high) == OTF2_SEVERITY_HIGH);

    static_assert(sizeof(marker_scope_type) == sizeof(OTF2_MarkerScope), "Enum size mismatch");
    assert(static_cast<int>(marker_scope_type::global) == OTF2_MARKER_SCOPE_GLOBAL);
    assert(static_cast<int>(marker_scope_type::location) == OTF2_MARKER_SCOPE_LOCATION);
    assert(static_cast<int>(marker_scope_type::location_group) == OTF2_MARKER_SCOPE_LOCATION_GROUP);
    assert(static_cast<int>(marker_scope_type::system_tree_node) ==
           OTF2_MARKER_SCOPE_SYSTEM_TREE_NODE);
    assert(static_cast<int>(marker_scope_type::group) == OTF2_MARKER_SCOPE_GROUP);
    assert(static_cast<int>(marker_scope_type::comm) == OTF2_MARKER_SCOPE_COMM);

    return 0;
}
