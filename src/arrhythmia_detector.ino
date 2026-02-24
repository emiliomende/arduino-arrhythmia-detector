/*
 * Real-Time Arrhythmia Detection Algorithm
 * Platform: Arduino UNO R4 (14-bit ADC)
 * Sampling Rate: 500 Hz
 *
 * Functionality:
 * - ECG acquisition via ADC
 * - RMS estimation over 300 samples
 * - R-peak detection using amplitude thresholding
 * - R-R interval measurement
 * - Heart rate calculation (BPM)
 *
 * Note: Experimental implementation for embedded DSP validation.
 */

// ===== Sampling Configuration =====
int sampleRate = 500;   // Sampling frequency (Hz)
const int  interrup = 1000000/sampleRate;   // Sampling period in microseconds
int in = 0; 

// ===== Peak Detection =====
float threshold; 
float previousValue = 0;

// ===== Timing Variables =====
unsigned long starttime;
unsigned long endtime;
unsigned long period;
float frec;



void setup(){
  Serial.begin(9600);
  analogReadResolution(14);
  pinMode(10, INPUT); 
  pinMode(11, INPUT); 
}
void loop() {
if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
Serial.println('!');
}
else{
in = analogRead(A0);
threshold = 7000; 
// Rising-edge detection: identifies threshold crossing
 if (in > threshold && previousValue <= threshold) {
    endtime = millis();
    // R-R interval measured in milliseconds
    period =  endtime - starttime;
    frec = 60000.0/period;

    Serial.print("period: "); 
    Serial.println(period);
    Serial.print("frec: "); 
    Serial.println(frec);
    Serial.println("Pico detectado!");
    Serial.print("Valor del pico: ");
    Serial.println(in);
    if (frec < 85){
      Serial.println("Posible bradicardia sinusal");
    }
    if (frec > 100){
      Serial.println("posible taquicardia sinusal");
    }
    starttime = millis();
    
  }

previousValue = in;
delayMicroseconds(interrup);
}
}
