/* Copyright (C) 2010-2019, The Regents of The University of Michigan.
 All rights reserved.

 This software was developed as part of the The Vulcan project in the Intelligent Robotics Lab
 under the direction of Benjamin Kuipers, kuipers@umich.edu. Use of this code is governed by an
 MIT-style License that can be found at "https://github.com/h2ssh/Vulcan".
*/


/**
 * \file     id.h
 * \author   Collin Johnson
 *
 * Declaration of Id and global functions for getting a globally unique id within a single process. There are about
 * nine quadrillion unique ids that can be generated using an hssh::Id.
 *
 * Functions:
 *
 *   load_next_id : load next id to assign from a file to allow persistence of id assignments across sessions.
 *   save_next_id : save the next id to assign to a file to allow peristence of id assignments across sessions.
 *   next_id      : generate the next unique id
 *
 * Constants:
 *
 *   kInvalidId : id that is guaranteed to never be returned by next_id.
 */

#ifndef HSSH_UTILS_ID_H
#define HSSH_UTILS_ID_H

#include <cstdint>
#include <string>

namespace vulcan
{
namespace hssh
{

using Id = int64_t;

/**
 * kInvalidId is an invalid identifier guaranteed never to be generated by next_id. Thus, setting unassigned values to
 * kInvalidId will guarantee detection of an uninitialized or unassigned value if next_id is always used to assign
 * valid ids.
 */
constexpr Id kInvalidId = -1;

/**
 * kFrontierId is an id to represent any sort of frontier area in the map. It indicates something that has been seen
 * but was never visited or was incompletely explored.
 */
constexpr Id kFrontierId = -2;

/**
 * kPathEndpointId is an id to assign to a transition the resides at the end of a path segment.
 */
constexpr Id kPathEndpointId = -3;

/**
 * kPathLoopId is an id to assign to a path segment that loops back to the start of the same path.
 */
constexpr Id kPathLoopId = -4;

/**
 * load_next_id loads the next id returned by next_id from a file. This functionality allows for the ids assigned by a
 * process to be persistent across runs of the process.
 *
 * \param    idFile          File containing the last assigned id
 * \return   True if the idFile existed and an id was loaded.
 */
bool load_next_id(const std::string& name);

/**
 * save_next_id saves the next id that would be returned by next_id to a file. This functionality allows for the ids
 * assigned by a process to be persistent across runs of the process as long as the next id is saved on module shutdown.
 *
 * \param    idFile          File containing the last assigned id
 * \return   True if the idFile existed and an id was loaded.
 */
bool save_next_id(const std::string& name);

/**
 * next_id retrieves the next unique in the id sequence.
 *
 * If the process is out of unique ids, then next_id will fail with exit(-1) as it is an unrecoverable error and likely
 * a programming error.
 *
 * \return   Unique id guaranteed not to be the same as any other id returned by next_id and not to be kInvalidId.
 */
Id next_id(void);

}   // namespace hssh
}   // namespace vulcan

#endif   // HSSH_UTILS_ID_H
