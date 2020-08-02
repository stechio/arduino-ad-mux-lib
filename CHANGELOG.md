# CHANGELOG | arduino-ad-mux-lib
Project arduino-ad-mux-lib (https://github.com/stechio/arduino-ad-mux-lib)

This file documents all notable changes to this project.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

Change author is referenced by nickname (@xxxxxx), as listed in [AUTHORS.md](AUTHORS.md); whenever unspecified, it's @stechio.

## [[Unreleased::feat/dev3](https://github.com/stechio/arduino-ad-mux-lib/tree/feat/dev3)]

This development iteration focuses on further API simplification (all ICs converged to a common implementation (`Mux`)), fluency (streamlined accessors and mutators), cohesiveness (name collisions prevented by namespace and constants encapsulation into enumerations) and generalization (arbitrary channel cardinality supported).

### Added
- `admux` namespace
- enumerations (`PinMode`, `PinType`): created to replace macro constants, type unsafe and prone to name clashing
- `Pin` struct: created to encapsulate full pin definitions (as for signal pin)
- `Pinset` struct: created to gather sets of coordinated pins (as for channel controls).
- `Mux.m_writePin` (see ADG726/ADG732)
- Travis CI configuration (@thijstriemstra)

### Changed
- `Mux`: fluent member naming, generalized control pin array (arbitrary channel cardinality supported)

### Fixed
- [[#3]](https://github.com/stechio/arduino-ad-mux-lib/issues/3) [ESP32] error: 'analogWrite' was not declared in this scope (@thijstriemstra)

### Removed
- `GenericMux`: replaced by `Mux`
- `Type4051Mux`: replaced by `Mux`
- `Type4067Mux`: replaced by `Mux`
- macro constants: encapsulated into enumerations

## [[2.0.1](https://github.com/stechio/arduino-ad-mux-lib/releases/tag/2.0.1)] - 2018-04-16

## [[2.0.0](https://github.com/stechio/arduino-ad-mux-lib/releases/tag/2.0.0)] - 2018-04-12

## [[1.0.0](https://github.com/stechio/arduino-ad-mux-lib/releases/tag/1.0.0)] - 2018-04-11
