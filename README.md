# Ultra-Lightweight Embedded Physics BMS Tracker 🔋

A highly optimized, bare-metal **Embedded C firmware module** implementing a mathematically Reduced-Order Model (ROM) for real-time lithium-ion cell state estimation. 

Designed specifically for resource-constrained BMS microcontrollers (**ARM Cortex-M** or similar) where heavy partial differential equation (PDE) physics engines cannot run.

## ⚡ Core Technical Metrics
* **RAM Footprint:** < 1.0 KB
* **Flash Footprint:** < 4.0 KB
* **Tracking Target Accuracy:** < 1.5% Root Mean Square Error (RMSE) under dynamic load cycles
* **Mathematical Framework:** Linear State-Space Boundary-Value Physics Approximation (Discrete Time Update Loop)

## 📁 Repository Structure
* `/bms_algorithm.c` - Core scalar-algebra cell state update matrix loop & hardware simulation harness.
* `/tune_model.py` - Optimization and parameter identification script matching PyBaMM baseline data to target discrete matrices.

## 🚀 Execution & Verification
The algorithm relies entirely on raw static arrays without dynamic allocation (`malloc`) to ensure safety and deterministic timing constraints on bare-metal systems.

To compile and verify the simulation footprint locally using GCC:
```bash
gcc bms_algorithm.c -o bms_engine && ./bms_engine
```

## 🎯 Commercial Applications
This framework is optimized for mid-tier, fast-growth battery applications where high-current draws or extreme thermal fluctuations cause standard Coulomb-counting software to drift:
* **Commercial Drone & Unmanned Aerial Vehicles (UAVs)** (Preventing unexpected voltage drops and mid-air cuts)
* **Micromobility & E-Bike Fleets** (Delivering linear, trustworthy range prediction)
* **Rugged Professional Power Tools** (State-of-Health monitoring under extreme thermal stress)

---
*Developed independently by Kieran (Kdev44). For licensing models, integration consulting options, or complete IP acquisition inquiries, please connect via LinkedIn.*
