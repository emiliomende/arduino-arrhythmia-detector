Arduino Arrhythmia Detector (Real-Time ECG Processing)
Overview

Experimental implementation of a real-time arrhythmia detection algorithm on Arduino UNO R4.
The system processes ECG signals acquired through an analog front-end module and performs peak detection and R-R interval analysis for heart rate calculation and irregular rhythm detection.

This project was developed for embedded DSP evaluation purposes and experimental validation.

Objectives:
  Acquire ECG signal via ADC.
  Detect R-peaks using amplitude thresholding.
  Compute heart rate using R-R interval measurement.
  Identify irregular rhythm patterns based on interval variation.
  Validate algorithm behavior using both real ECG signals and signal generator testing.

Hardware Setup:
  Arduino UNO R4 (RA4M1 – ARM Cortex-M4)
  ECG analog front-end module (with built-in filtering stage)
  Signal generator (used for experimental validation)
  Serial monitor for debugging and output analysis

Signal Processing Flow:
  1.-Real-time ECG acquisition via ADC.
  2.-Filtered signal input from analog front-end.
  3.-Peak detection using dynamic amplitude threshold.
  4.-R-R interval measurement.
  5.-Heart rate calculation:
    Heart Rate (BPM) = 60 / (R-R interval in seconds)
  6.-Detection of irregular patterns based on abnormal interval variation.

Experimental Validation

Two testing stages were performed:
  Real ECG acquisition (self-recorded signal).
  Controlled waveform testing using signal generator.

This allowed validation of:
  Peak detection stability
  Interval measurement accuracy
  System response consistency

Real-Time Considerations:
  Processing executed inside main loop.
  Timing verified using micros().
  No external RTOS used.
  Designed under memory and timing constraints of embedded hardware.

Limitations
  Simplified arrhythmia detection logic.
  No clinical-grade validation.
  Fixed threshold approach.
  Limited sampling resolution.

Future Improvements 
  Adaptive thresholding.
  Digital band-pass filtering optimized for ECG.
  Noise rejection improvements.
  Fixed-point optimization.
  Data logging and visualization integration.

Disclaimer
This implementation is for experimental and educational purposes only and is not intended for medical diagnosis.
