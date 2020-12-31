/* Copyright (C) 2010-2019, The Regents of The University of Michigan.
 All rights reserved.

 This software was developed as part of the The Vulcan project in the Intelligent Robotics Lab
 under the direction of Benjamin Kuipers, kuipers@umich.edu. Use of this code is governed by an
 MIT-style License that can be found at "https://github.com/h2ssh/Vulcan".
*/


/**
 * \file     params.h
 * \author   Collin Johnson
 *
 * Declaration of goal_params_t and load_goal_params function.
 */

#ifndef PLANNER_GOAL_PARAMS_H
#define PLANNER_GOAL_PARAMS_H

#include <string>

namespace vulcan
{
namespace utils
{
class ConfigFile;
}

namespace planner
{

struct goal_params_t
{
};

/**
 * load_goal_params loads the parameters for the global topo planner from
 * the provided config file.
 *
 * \param    config          Config file with the parameters
 * \return   Struct contained the parameters parsed from the config.
 */
goal_params_t load_goal_params(const utils::ConfigFile& config);

}   // namespace planner
}   // namespace vulcan

#endif   // PLANNER_GOAL_PARAMS_H
