// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include "DolphinQt/Config/Mapping/HotkeyControllerProfile.h"

#include <QGridLayout>
#include <QGroupBox>

#include "Core/HotkeyManager.h"

HotkeyControllerProfile::HotkeyControllerProfile(MappingWindow* window) : MappingWidget(window)
{
  CreateMainLayout();
}

void HotkeyControllerProfile::CreateMainLayout()
{
  m_main_layout = new QGridLayout;

  m_main_layout->addWidget(
      CreateGroupBox(tr("Wii Remote %1").arg(1),
                     HotkeyManagerEmu::GetHotkeyGroup(HKGP_CONTROLLER_PROFILE_1)),
      0, 0);

  m_main_layout->addWidget(
      CreateGroupBox(tr("Wii Remote %2").arg(2),
                     HotkeyManagerEmu::GetHotkeyGroup(HKGP_CONTROLLER_PROFILE_2)),
      0, 1);

  m_main_layout->addWidget(
      CreateGroupBox(tr("Wii Remote %3").arg(3),
                     HotkeyManagerEmu::GetHotkeyGroup(HKGP_CONTROLLER_PROFILE_3)),
      1, 0);

  m_main_layout->addWidget(
      CreateGroupBox(tr("Wii Remote %4").arg(4),
                     HotkeyManagerEmu::GetHotkeyGroup(HKGP_CONTROLLER_PROFILE_4)),
      1, 1);

  setLayout(m_main_layout);
}

InputConfig* HotkeyControllerProfile::GetConfig()
{
  return HotkeyManagerEmu::GetConfig();
}

void HotkeyControllerProfile::LoadSettings()
{
  HotkeyManagerEmu::LoadConfig();
}

void HotkeyControllerProfile::SaveSettings()
{
  HotkeyManagerEmu::GetConfig()->SaveConfig();
}
