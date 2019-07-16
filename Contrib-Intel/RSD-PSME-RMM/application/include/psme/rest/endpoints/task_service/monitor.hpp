/*!
 * @copyright
 * Copyright (c) 2016-2019 Intel Corporation
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

#pragma once
#include "psme/rest/endpoints/endpoint_base.hpp"


namespace psme {
namespace rest {
namespace endpoint {



/*!
 * A class representing the rest api Root endpoint
 */
class Monitor : public EndpointBase {
public:

    /*!
     * @brief Constructor
     */
    explicit Monitor(const std::string& path);

    /*!
     * @brief Root class destructor
     */
    virtual ~Monitor();

    void get(const server::Request& request, server::Response& response) override;

private:
    std::string service_root_name{};
};

}
}
}