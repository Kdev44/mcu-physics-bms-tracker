#include <stdio.h>

// Define battery state dimensions (2 internal tracking states)
#define STATES 2

// --- COPY AND PASTE THESE NEW MATRICES INTO YOUR WEEK 3 C CODE ---
const float A[STATES][STATES] = {
    {1.0326f, 0.0000f}, 
    {0.0000f, 0.9062f}
};
const float B[STATES][1] = {
    {-0.0518f}, 
    {0.1222f}
};
const float C[STATES] = {0.9139f, -0.6149f};
const float D = -0.1931f;
const float V_NOMINAL = 3.6247f;

// Persistent battery internal concentration states
static float x1 = 1.0f;
static float x2 = 1.0f;

// Hyper-fast function that hardware chips use to predict voltage
float bms_update_physics(float current_input) {
    // 1. Calculate next states using your scalar algebra formula
    float x1_next = A[0][0] * x1 + B[0][0] * current_input;
    float x2_next = A[1][1] * x2 + B[1][0] * current_input;
    
    // 2. Save the updated states
    x1 = x1_next;
    x2 = x2_next;
    
    // 3. Output the hyper-accurate predicted voltage
    float predicted_voltage = (C[0] * x1 + C[1] * x2) + D * current_input + V_NOMINAL;
    
    return predicted_voltage;
}

// Simple test harness to prove the code compiles and runs
int main() {
    printf("Initializing Embedded BMS Physics Engine...\n");
    
    // Test with a standard 1.0 Amp continuous motor load draw
    float test_current = 1.0f;
    float voltage_prediction;
    
    printf("\nSimulating first 5 seconds of device usage:\n");
    for (int second = 1; second <= 5; second++) {
        voltage_prediction = bms_update_physics(test_current);
        printf("Second %d | Current: %.1fA | Predicted Voltage: %.4fV\n", 
               second, test_current, voltage_prediction);
    }
    
    return 0;
}
