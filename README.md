Overview

Implementation of a basic arrhythmia detection algorithm on Arduino UNO R4 for experimental evaluation of real-time signal processing capabilities.

Objective

To analyze ECG-like signals in real time and detect irregular heart rhythm patterns using threshold-based peak detection and interval analysis.

Hardware

Arduino UNO R4

Analog signal input (ECG / simulated waveform)

Serial monitoring for debugging and output visualization

Algorithm Description

Signal acquisition via ADC.

Optional filtering stage.

Peak detection using amplitude threshold.

R-R interval calculation.

Detection of irregular intervals indicating potential arrhythmia.

Real-Time Considerations

Execution within loop cycle.

Timing measurements using micros().

Memory constraints evaluation.

Limitations

Simplified detection logic.

No clinical validation.

Limited sampling resolution.

Future Improvements

Adaptive thresholding.

Digital filtering (band-pass optimized for ECG).

Fixed-point optimization.

Reference oscillator integration.
