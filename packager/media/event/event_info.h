// Copyright 2018 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd
//
// Defines EventInfo structure used internally by muxer listeners for VOD.

#ifndef PACKAGER_MEDIA_EVENT_EVENT_INFO_H_
#define PACKAGER_MEDIA_EVENT_EVENT_INFO_H_

#include <cstdint>

namespace shaka {
namespace media {

// This stores data passed into OnNewSegment() for VOD.
struct SegmentEventInfo {
  uint64_t start_time;
  // The below two fields are only useful for Segment.
  uint64_t duration;
  uint64_t segment_file_size;
};

// This stores data passed into OnCueEvent() for VOD.
struct CueEventInfo {
  uint64_t timestamp;
};

// This stores data for lazy event callback for VOD.
struct EventInfo {
  bool is_cue_event;
  union {
    SegmentEventInfo segment_info;
    CueEventInfo cue_event_info;
  };
};

}  // namespace media
}  // namespace shaka

#endif  // PACKAGER_MEDIA_EVENT_EVENT_INFO_H_
