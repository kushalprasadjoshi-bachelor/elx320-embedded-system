# Xilinx ISE 14.7 Setup Guide

This project uses **Xilinx ISE Design Suite 14.7**. 
Because ISE 14.7 is a legacy tool, the easiest and most reliable way to run it on modern computers is through a **Virtual Machine (VM)**.

This guide explains how to set it up on **Windows**, **Linux**, and **macOS (Intel only)**.

ISE 14.7 is a legacy FPGA development tool and does not run natively on modern systems, so we run it inside a **Linux Virtual Machine using VirtualBox**.
This guide explains how to install and run **Xilinx ISE Design Suite 14.7** using a **Virtual Machine** so it works on modern operating systems such as **Windows 10 / Windows 11**.

---

## Supported systems

This setup is intended for:

- **Windows 10 / Windows 11** on Intel or AMD
- **Linux x86_64** (Ubuntu, Debian, Fedora, etc.)
- **macOS Intel**

Not supported:

- **Apple Silicon Macs (M1 / M2 / M3 / M4)**
- ARM-only systems unless you already know how to run x86 virtual machines on them

---

## What you need

Before starting, make sure you have:

- A CPU with virtualization support
- At least **8 GB RAM** recommended
- At least **40 GB free disk space**
- Administrator access on your computer
- Internet access for downloads

| Requirement | Minimum |
|-------------|---------|
| RAM | 8 GB recommended |
| Disk space | 40 GB free |
| CPU | Intel / AMD with virtualization |
| OS | Windows 10 / Windows 11 / Linux / MacOS (Intel Only) |

---

## Important warnings

- **Do not use VirtualBox 7.x** for this VM unless you have tested it yourself.
- **VirtualBox 6.1.x** is the safest choice for ISE 14.7 VM compatibility.
- If you see errors like **`E_INVALIDARG (0x80070057)`**, the most common causes are:
  - wrong VirtualBox version
  - corrupted extraction of the OVA
  - Windows virtualization features still enabled
  - a long file path with spaces or special characters

For best results, keep the VM files in a short path such as:

```text
C:\ISE_VM\
````

or

```text
D:\ISE_VM\
```

---


## Download links

### 1) VirtualBox

Download **VirtualBox 6.1.x** from the official Oracle archive:

* Oracle VirtualBox 6.1 old builds:
  [https://www.virtualbox.org/wiki/Download_Old_Builds_6_1](https://www.virtualbox.org/wiki/Download_Old_Builds_6_1)

If you need the Extension Pack, use the matching version from the same archive.

### 2)  Download Xilinx ISE 14.7 

Download ISE 14.7 VM for Windows 10 & 11:
[https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/archive-ise.html](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/archive-ise.html)

Download: 14.7 Windows 10 and Windows 11 (TAR/GZIP)

You will get:
```
Xilinx_ISE_14.7_Win10_14.7_VM_0213_1.zip
```

This file is several GB in size.

**Official AMD documentation for the ISE VM:**

* ISE 14.7 VM for Windows 10 & 11 User Guide (UG1227):
  [https://docs.amd.com/r/en-US/ug1227-ise-vm-windows10](https://docs.amd.com/r/en-US/ug1227-ise-vm-windows10)

### 4.2 Install 7-Zip (Required)

We need **7-Zip** to extract the VM files.

Download:
https://www.7-zip.org/download.html

Install it normally.

---

## Install VirtualBox

### Windows

1. Download the VirtualBox installer from the official Oracle archive. (We have already done.)
2. Install VirtualBox (run the downloaded file).
3. Restart your computer.

### Linux

Install VirtualBox using your distribution package manager or the Oracle package for your distro.

### macOS (Intel only)

Install the macOS VirtualBox package from the Oracle archive.
Restart after installation.

---

## Enable virtualization in BIOS/UEFI

The VM will not work unless CPU virtualization is enabled.

### How to check

When your computer is booting:

* HP: press `ESC` then `F10`
* Dell: often `F2`
* Lenovo: often `F1` or `F2`
* ASUS: often `F2`
* Acer: often `F2`
* MSI: often `DEL`

Inside BIOS/UEFI, look for one of these options:

* `Intel Virtualization Technology`
* `VT-x`
* `AMD-V`
* `SVM Mode`
* `Virtualization Technology`

Enable it, save, and reboot.

### On Windows

You can also reach UEFI from:

`Settings → System → Recovery → Advanced startup → Restart now → Troubleshoot → Advanced options → UEFI Firmware Settings`

---

## Disable Windows features that block VirtualBox

This step is important on Windows 10/11.

### 1) Turn off Windows optional features

Open:

```text
Win + R → optionalfeatures
```

Then uncheck:

* `Hyper-V`
* `Virtual Machine Platform`
* `Windows Hypervisor Platform`
* `Windows Sandbox`
* `Windows Subsystem for Linux` (optional, but recommended if you keep getting VM conflicts)

Click **OK** and restart.

### 2) Disable Memory Integrity

Open:

```text
Windows Security → Device security → Core isolation
```

Turn off:

* `Memory integrity`

Restart again.

### 3) Disable the Windows hypervisor launch

Open **Command Prompt as Administrator** and run:

```cmd
bcdedit /set hypervisorlaunchtype off
```

Restart again.

### 4) Verify virtualization status

Open **Task Manager** → `Performance` → `CPU`

You should see:

```text
Virtualization: Enabled
```

You can also run:

```cmd
systeminfo
```

and check that virtualization is enabled in firmware and that no hypervisor is detected.

**Restart your computer.**

---

## Extract the VM Files

### Step 1: Extract the ZIP file

Right click the downloaded file
```
Xilinx_ISE_14.7_Win10_14.7_VM_0213_1.zip
```

Select
```
7-Zip → Extract Here
```

Example folder structure after extraction:
```
Xilinx_ISE_14.7_Win10_14.7_VM_0213_1/
```

---

### Step 2: Open the OVA folder

Navigate to
```
Xilinx_ISE_14.7_Win10_14.7_VM_0213_1/ova/
```

Inside you will see
```
14.7_VM.ova
```

---

### Step 3: Extract the OVA file

Right click
```
14.7_VM.ova
```

Select
```
7-Zip → Extract Here
```

After extraction you will get:

```
14.7_VM.ovf
14.7_VM-disk001.vmdk
```

---

##  Create the Virtual Machine

Open **Oracle VirtualBox**.

Click
```
New
```

Fill the fields as follows:

| Setting | Value |
|-------|------|
| Name | Xilinx ISE 14.7 |
| Type | Linux |
| Version | Oracle (64-bit) |

---

### Allocate Memory

Set memory size:
```
2048 MB (2GB)
```

---

### Attach the Virtual Hard Disk

Choose
```
Use an existing virtual hard disk file
```

**Click the folder icon.**

Select:

```
14.7_VM-disk001.vmdk
```

Then click

```
Create
```

---

## Start the Virtual Machine

**Select the VM.**

Click

```
Start
```

The Linux system will boot.

After booting, **Xilinx ISE 14.7 will be available inside the VM**.

---

## Share files between host and VM

Use a shared folder so your project files can be edited on the host and opened in the VM.

### Create a shared folder on the host

Example:

```text
C:\VM_Share
```

### Add it in VirtualBox

In VirtualBox:

```text
Settings → Shared Folders → Add
```

Choose:

* **Folder Path**: `C:\VM_Share`
* **Folder Name**: `share`
* Enable `Auto-mount`
* Enable `Make Permanent`

### Access inside the VM

The shared folder usually appears at:

```text
/media/sf_share
```

or:

```text
/mnt/share
```

If permission is denied, add your user to the shared-folder group and reboot the VM:

```bash
sudo usermod -aG vboxsf $USER
```

---

## Troubleshooting

### 1) Error: “Please enable virtualization in BIOS”

Check all of the following:

* Virtualization is enabled in BIOS/UEFI
* `Hyper-V` is disabled
* `Virtual Machine Platform` is disabled
* `Windows Hypervisor Platform` is disabled
* `Memory integrity` is off
* You restarted after each change

### 2) Error: `E_INVALIDARG (0x80070057)`

This usually means the VM import was rejected.

Try these fixes:

* Use **VirtualBox 6.1.x**
* Keep the VM folder path short
* Re-extract the OVA if needed
* Make sure the `.ovf` and `.vmdk` files are complete and not renamed
* Remove any stale partial VM import and try again

### 3) Error: `VBoxManage.exe is not recognized`

This means VirtualBox is not installed correctly or the path is missing.

Check that this file exists:

```text
C:\Program Files\Oracle\VirtualBox\VBoxManage.exe
```

If it exists, add this folder to your system `Path`.

### 4) VERR_NOT_SUPPORTED error

This happens if the `.vmdk` file was not extracted correctly.

Re-extract the `.ova` using **7-Zip**.

### 5) VM starts but is very slow

Try:

* close heavy apps on the host
* give the VM `2 GB` to `4 GB` RAM
* use only `1` or `2` CPU cores
* disable 3D acceleration

### 6) Import fails on a fresh Windows 11 installation

Double-check:

* Hyper-V is off
* Virtual Machine Platform is off
* Windows Hypervisor Platform is off
* Memory integrity is off
* no other VM software is fighting for virtualization

### 7) Secure Boot / OEM policy keeps turning virtualization features back on

Some laptops enforce security features more aggressively.

If the normal Windows steps do not work:

* re-check BIOS/UEFI settings
* confirm that the Windows hypervisor is still off after reboot
* temporarily disable Secure Boot only if your institution allows it and only if necessary for this lab setup

---

*Thank you for reading!*
