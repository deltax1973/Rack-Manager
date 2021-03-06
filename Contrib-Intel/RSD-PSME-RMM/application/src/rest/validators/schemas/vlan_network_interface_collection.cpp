/*!
 * @copyright
 * Copyright (c) 2015-2019 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */

#include "psme/rest/validators/schemas/vlan_network_interface_collection.hpp"
#include "psme/rest/constants/constants.hpp"

using namespace psme::rest;
using namespace psme::rest::validators::schema;

const jsonrpc::ProcedureValidator& VlanNetworkInterfaceCollectionPostSchema::OemSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Common::RACKSCALE, VALID_ATTRIBUTE(RackScaleSchema),
        nullptr
    };
    return procedure;
}

const jsonrpc::ProcedureValidator& VlanNetworkInterfaceCollectionPostSchema::OemSchema::RackScaleSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Vlan::TAGGED, VALID_JSON_BOOLEAN,
        nullptr
    };
    return procedure;
}

const jsonrpc::ProcedureValidator& VlanNetworkInterfaceCollectionPostSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Common::NAME, VALID_OPTIONAL(VALID_JSON_STRING),
        constants::Common::OEM, VALID_ATTRIBUTE(OemSchema),
        constants::Vlan::VLAN_ENABLE, VALID_JSON_BOOLEAN,
        constants::Vlan::VLAN_ID, VALID_NUMERIC_TYPED(UINT32),
        nullptr
    };
    return procedure;
}
