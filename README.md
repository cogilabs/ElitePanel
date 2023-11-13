# ElitePanel
[→ En Français](/localizedReadme/README-fr.md)

<p align="center">
    <!--<img alt="Banner" title="Banner" src="/readme_sources/images/banner.png">-->
</p>
<p align="center">
    <a href="https://electronjs.org/" target="_blank"><img alt="Electron badge" title="Built with Electron!" src="https://img.shields.io/badge/Electron-4E44B6?style=for-the-badge&logo=electron&logoColor=white"/></a>
    <a href="https://vuejs.org/" target="_blank"><img alt="Vue.js badge" title="Using Vue.js!" src="https://img.shields.io/badge/Vue.js-4FC08D?style=for-the-badge&logo=vue.js&logoColor=white"/></a>
    </br>
    <a href="https://www.arduino.cc/" target="_blank"><img alt="Arduino badge" title="Using Arduino!" src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white"/></a>
    <a href="https://www.espressif.com/en/products/socs/esp32" target="_blank"><img alt="ESP32 badge" title="Using ESP32!" src="https://img.shields.io/badge/ESP32-DD4A23?style=for-the-badge&logo=espressif&logoColor=white"/></a>
</p>

## ⚠️ Warning: Work in Progress ⚠️

The **Cogilabs ElitePanel** is a configurable control panel designed for simulation games.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Configuration](#configuration)
- [Hardware Setup](#hardware-setup)
- [Arduino (ESP32) Integration](#arduino-esp32-integration)

## Introduction

The **ElitePanel Control App** is an Electron-based software made to configure the **ElitePanel**, a control panel designed for simulation games such as Elite Dangerous and American Truck Simulator. It allows users to create, modify, and save profiles for buttons and levers, providing custom key mappings and configurations.

## Features

- **Custom Key Mapping:** Define and customize keystrokes for buttons and levers.
- **Profile Management:** Create and save different profiles for different games or setups.
- **Interactive Configuration:** Modify key assignments and configurations through a user-friendly interface.

## Getting Started

To use the **ElitePanel Control App**, follow these steps:

1. **Installation:** Clone or download the repository.
2. **Dependencies:** Ensure you have Node.js and npm installed.
3. **Setup:** Run `npm install` to install the necessary packages.
4. **Launch:** Execute the app with `npm start`.

## Usage

1. Plug in the panel via USB to your computer.
2. Select the right COM Port.
3. Configure your keys.
4. Enjoy!

## Configuration

The app allows you to configure:

- **Key Mappings:** Define specific keys or actions for each button or lever.
- **Profiles:** Create, edit, and delete profiles for different game setups.

## Hardware Setup

The ElitePanel hardware consists of a physical control panel featuring buttons and levers. Here's an image of the panel:

![ElitePanel Hardware](/readme_sources/images/panelPhoto.png)

## Arduino (ESP32) Integration

The ElitePanel is powered by an ESP32 microcontroller. The Arduino code for the ESP32 integration is available in the `esp32_code` directory in this repository.  

It features:
 - A standalone code, that doesn't use the **ElitePanel Control App** and is ready to go for my config of Elite Dangerous. You can directly customize the program to modify keys → [Here](/esp32_code/standalone/standalone.ino)
 - [WIP] A programmable version of the code, built to work with the **ElitePanel Control App** and to have customisable outputs → [Here](/esp32_code/pcProgrammable/pcProgrammable.ino)