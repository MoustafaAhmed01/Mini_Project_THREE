# Mini_Project_THREE
Fan Controller
**Fan Controller System Implementation**

**Specifications:**

1. Design a temperature-controlled fan using ATmega32 microcontroller with a clock frequency of 1MHz.
2. Use LM35 temperature sensor for analog temperature sensing.
3. Convert analog output from LM35 to digital values using ADC.
4. Perform calculations in microcontroller to get temperature from ADC values.
5. Display temperature on LCD screen.
6. Control fan speed based on temperature:
   a. Turn off fan if temperature < 30°C.
   b. Turn on fan at 25% speed if temperature ≥ 30°C.
   c. Turn on fan at 50% speed if temperature ≥ 60°C.
   d. Turn on fan at 75% speed if temperature ≥ 90°C.
   e. Turn on fan at 100% speed if temperature ≥ 120°C.
7. Use PWM signal generated from Timer0 to control DC-motor speed.
8. Follow layered architecture model for project design and implementation.

**Drivers Requirements:**

1. **ADC Driver:**
   - Implement full ADC driver with polling design.
   - Modify ADC_init to take ADC_ConfigType structure pointer.
   - ADC_ConfigType structure:
     ```
     typedef struct {
       ADC_ReferenceVolatge ref_volt;
       ADC_Prescaler prescaler;
     } ADC_ConfigType;
     ```
2. **GPIO Driver:**
   - Use existing GPIO driver.
   
3. **LCD Driver:**
   - Use existing LCD driver with 8-bits data mode.
   - Connect LCD control pins and data pins accordingly.

4. **Temperature Sensor Driver:**
   - Use existing Temperature Sensor driver.
   - Connect LM35 to ADC channel 2.

5. **DC-Motor Driver:**
   - Implement full DC-Motor Driver with:
     ```
     void DcMotor_Init(void);
     void DcMotor_Rotate(DcMotor_State state, uint8 speed);
     ```
   - DcMotor_Init: Setup motor direction and stop motor.
   - DcMotor_Rotate: Rotate motor CW/ACW or stop based on state, adjust PWM duty cycle based on speed.

6. **PWM Driver:**
   - Utilize existing PWM Timer0 function with:
     ```
     void PWM_Timer0_Start(uint8 duty_cycle);
     ```
   - Trigger Timer0 with PWM mode, setup non-inverting mode, prescaler F_CPU/8, set compare value for duty cycle, set OC0 direction.

**Project Structure:**

1. Temperature sensing using LM35 and ADC.
2. Temperature calculation and LCD display.
3. Fan control logic based on temperature.
4. DC-motor control using PWM.
5. Layered architecture model.
