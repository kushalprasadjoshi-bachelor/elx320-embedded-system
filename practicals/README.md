# VHDL Laboratory Projects (Xilinx ISE)

This repository contains **VHDL source code (`.vhd`) only** with a **ISE project defination** for Embedded Systems laboratory experiments.
All tool-generated files are intentionally excluded to keep the project **clean, portable, and reproducible**.

The projects/labs are designed to be opened and run on **any system with the same Xilinx ISE environment**.

---

## 📁 Repository Structure

```text
.
├── images
│    ├── lab01
│    ├── lab02
│    ├── ..............
│    │
|
├── docs
│    ├── lab01
│    ├── lab02
│    ├── ..............
│    │
│
├── practicals/
│   ├── lab01-introduction-to-vhdl/
│   │   └── *.vhd
│   ├── lab02-adder-circuits/
│   │   └── *.vhd
│   ├──lab03-behavioural-design-mux/
│   │   └── *.vhd
│   ├── ...............
│   │
│
│
├── theory
│    ├── ............
│    ├── ...........
│    ├── ..............
│    │
│ 
├── README.md
└── .gitignore
```

Each lab folder inside practicals contains **only VHDL source files**, which are the actual deliverables of the lab work.

**ISE project defination** file is also added in each folder for the easy opening and running of the projects in the Xilinks ISE environment.

The **outputs** from the lab experiment are added in the images folder under which we have the subfolders for each project/lab.

We also have the printable output documents under the `docs/` folder for each labs.

---

## 🛠️ Requirements

To run these projects/labs in your system, you need:

* **Xilinx ISE Design Suite** (compatible version)
* A supported operating system (typically Windows)
* Basic knowledge of creating a project in Xilinx ISE

No additional files are required.

---

## 🚀 How to Use on Another Device

Follow these steps **after cloning the repository**:

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/kushalprasadjoshi-bachelor/elx320-embedded-system
```

---

### 2️⃣ Open Xilinx ISE

Launch **Xilinx ISE Design Suite** on your system.

---

### 3️⃣ Create a New Project

* Click **New Project**
* Choose:

  * Project Type: *HDL*
  * Top-Level Source Type: *HDL*
* Select the appropriate **device, package, and speed** as required by your lab

---

### 4️⃣ Add Existing VHDL Files

* Right-click **Hierarchy** → *Add Source*
* Add the required `.vhd` files from the cloned lab folder

---

### 5️⃣ Run the Project

You can now:

* **Synthesize**
* **Implement Design**
* **Simulate using ISim**

Xilinx ISE will automatically regenerate:

* Project files
* Simulation folders
* Reports
* Logs
* Bitstreams (if required)

---

### ✅ Open ISE Project Defination After Cloning

If you want to use these projects in easy way, you just have to clone the repository and open the `ISE project defination` that is present in each lab.
No need of the steps 2️⃣3️⃣4️⃣5️⃣ in this case.

---

## 📌 Why Only `.vhd` Files Are Tracked

* `.vhd` files contain the **actual logic and design**
* All other files are **tool-generated**
* Generated files are:

  * Machine-dependent
  * Automatically recreated
  * Not required for portability

This approach ensures:
✔ Clean repository
✔ Easy cloning
✔ No path or environment issues
✔ Professional workflow

`.xise` files are also tracked for easy opening of project in **Xilinx ISE Environment**.

---

## 🎓 Academic Note

This repository follows **standard academic and industry practices** for VHDL projects.
Only source files are tracked to ensure **clarity, correctness, and reproducibility**.

---

Thank you!

