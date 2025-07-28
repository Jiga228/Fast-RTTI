# Fast-RTTI
This library implements fast RTTI for C++.

Tests:
[Direct type casting]
dynami_cast: 202ms
RTTI::dyn_cast: 54ms
[Possible type casting]
dynami_cast: 193ms
RTTI::dyn_cast: 41ms
[Not possible type casting]
dynami_cast: 489ms
RTTI::dyn_cast: 43ms
