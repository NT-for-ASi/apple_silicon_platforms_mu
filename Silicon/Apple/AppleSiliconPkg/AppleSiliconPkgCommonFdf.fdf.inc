#
# Copyright (c) 2026 NTASP authors.
# 
# Module name:
#   AppleSiliconPkgCommonFdf.fdf.inc
#
# Description:
#   The common FDF file that defines packages to be included for all platforms in the resultant FD image.
#
# Environment:
#   Stuart build environment.
#
# License:
#   SPDX-License-Identifier: BSD-2-Clause-Patent OR MIT
#

# Continues [Fv.FvMain]
  # Main DXE core
  INF MdeModulePkg/Core/Dxe/DxeMain.inf

  #
  # PI DXE Drivers producing Architectural Protocols (EFI Services)
  #
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF AppleSiliconPkg/Drivers/AppleDartIoMmuDxe/AppleDartIoMmuDxe.inf

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
!if $(SECURE_BOOT_ENABLE) == TRUE
  INF SecurityPkg/VariableAuthenticated/SecureBootConfigDxe/SecureBootConfigDxe.inf
!endif

  #
  # Multiple Console IO support
  #
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  INF MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
!if $(AIC_BUILD) == FALSE
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
!else 
  INF AppleSiliconPkg/Drivers/AppleAicDxe/AppleAicDxe.inf
!endif
  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf

  INF AppleSiliconPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf

  #
  # PCIe Support (required to bring up USB-A among other fun stuff)
  #
  INF ArmPkg/Drivers/ArmPciCpuIo2Dxe/ArmPciCpuIo2Dxe.inf
  INF MdeModulePkg/Bus/Pci/PciHostBridgeDxe/PciHostBridgeDxe.inf
  INF MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
  INF MdeModulePkg/Bus/Pci/NonDiscoverablePciDeviceDxe/NonDiscoverablePciDeviceDxe.inf

  #NVMe Support
  #TODO: ANS2/SART driver
  #INF AppleSiliconPkg/Drivers/AppleANS2Dxe/AppleANS2Dxe.inf
  #INF MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf

  #
  # Virtual Keyboard
  #
  INF EmbeddedPkg/Drivers/VirtualKeyboardDxe/VirtualKeyboardDxe.inf
  #INF OemPkg/FrontpageButtonsVolumeUp/FrontpageButtonsVolumeUp.inf

  # FV FileSystem
  INF MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf

  INF AppleSiliconPkg/Drivers/AppleEmbeddedGpioControllerDxe/AppleEmbeddedGpioControllerDxe.inf
  #
  # PCIe support is disabled for now.
  #
  #INF AppleSiliconPkg/Drivers/AppleSiliconPciPlatformDxe/AppleSiliconPciPlatformDxe.inf
  #INF AppleSiliconPkg/Drivers/AppleBootTimeEmbeddedFirmwareHelperDxe/AppleBootTimeEmbeddedFirmwareHelperDxe.inf

  #
  # DWC3 bringup module.
  #
  INF AppleSiliconPkg/Drivers/AppleUsbTypeCBringupDxe/AppleUsbTypeCBringupDxe.inf

  #
  # Usb Support
  #
  INF  MdeModulePkg/Bus/Pci/UhciDxe/UhciDxe.inf
  INF  MdeModulePkg/Bus/Pci/EhciDxe/EhciDxe.inf
  INF  MdeModulePkg/Bus/Pci/XhciDxe/XhciDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMouseAbsolutePointerDxe/UsbMouseAbsolutePointerDxe.inf
  #
  # USB Host Support
  #
  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf

  #
  # USB Mass Storage Support
  #
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf
  #
  # Some miscellaneous Mu modules
  #
  INF  MsCorePkg/Universal/StatusCodeHandler/Serial/Dxe/SerialStatusCodeHandlerDxe.inf
  INF  MsCorePkg/MuVarPolicyFoundationDxe/MuVarPolicyFoundationDxe.inf

  #
  # FAT filesystem + GPT/MBR partitioning
  #
  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  INF MdeModulePkg/Universal/Disk/RamDiskDxe/RamDiskDxe.inf
  INF AppleSiliconPkg/Drivers/BootRamdiskHelperDxe/BootRamdiskHelperDxe.inf


  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf

  #
  # ACPI Support
  #
  INF MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
  INF AppleSiliconPkg/Drivers/AcpiPlatformDxe/AcpiPlatformDxe.inf
  INF MdeModulePkg/Universal/Acpi/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf
  INF RuleOverride=ACPITABLE AppleSiliconPkg/AcpiTables/GenericAcpiTables.inf

  #
  # SMBIOS Support
  #
  INF AppleSiliconPkg/Drivers/SmbiosInfoDxe/SmbiosInfoDxe.inf
  INF MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf

  #
  # UEFI applications
  #
  INF ShellPkg/Application/Shell/Shell.inf
!ifdef $(INCLUDE_TFTP_COMMAND)
  INF ShellPkg/DynamicCommand/TftpDynamicCommand/TftpDynamicCommand.inf
!endif #$(INCLUDE_TFTP_COMMAND)

  #
  # Bds
  #
  INF AppleSiliconPkg/Drivers/ColorbarsDxe/ColorbarsDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
  INF MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
  INF MdeModulePkg/Universal/DriverHealthManagerDxe/DriverHealthManagerDxe.inf
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  # DT
  #INF EmbeddedPkg/Drivers/DtPlatformDxe/DtPlatformDxe.inf

  FILE FREEFORM = PCD(gMsCorePkgTokenSpaceGuid.PcdRegulatoryGraphicFileGuid) {
    SECTION RAW = MacBookAirMid2020Pkg/Resources/RegulatoryLogos.png
  }

  # Embedded RAMDisk (ISO format)
  #FILE FREEFORM = 650B7CD0-94F8-46CC-88DE-8C199D41EDA3 {
  #SECTION RAW = AppleSiliconPkg/RAMDisk/WinPE.iso
  #SECTION UI = "Embedded RAMDisk"  
#}

  # Embedded RAMDisk (IMG format)
  #FILE FREEFORM = 650B7CD0-94F8-46CC-88DE-8C199D41EDA3 {
  #SECTION RAW = AppleSiliconPkg/RAMDisk/WinPE.img
  #SECTION UI = "Embedded RAMDisk"  
#}