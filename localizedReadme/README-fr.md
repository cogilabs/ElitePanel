# ElitePanel
[→ In English](/README.md)

<p align="center">
    <!--<img alt="Bannière" title="Bannière" src="/readme_sources/images/banner.png">-->
</p>
<p align="center">
    <a href="https://electronjs.org/" target="_blank"><img alt="Badge Electron" title="Construit avec Electron !" src="https://img.shields.io/badge/Electron-4E44B6?style=for-the-badge&logo=electron&logoColor=white"/></a>
    <a href="https://vuejs.org/" target="_blank"><img alt="Badge Vue.js" title="Utilise Vue.js !" src="https://img.shields.io/badge/Vue.js-4FC08D?style=for-the-badge&logo=vue.js&logoColor=white"/></a>
    </br>
    <a href="https://www.arduino.cc/" target="_blank"><img alt="Badge Arduino" title="Utilise Arduino !" src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white"/></a>
    <a href="https://www.espressif.com/en/products/socs/esp32" target="_blank"><img alt="Badge ESP32" title="Utilise ESP32 !" src="https://img.shields.io/badge/ESP32-DD4A23?style=for-the-badge&logo=espressif&logoColor=white"/></a>
</p>

## ⚠️ Avertissement : Développement en Cours ⚠️

L'**ElitePanel** est un panneau de contrôle configurable conçu pour les jeux de simulation.

## Table des Matières

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Pour Commencer](#pour-commencer)
- [Utilisation](#utilisation)
- [Configuration](#configuration)
- [Configuration Matérielle](#configuration-matérielle)
- [Intégration Arduino (ESP32)](#intégration-arduino-esp32)

## Introduction

L'**ElitePanel Control App** est un logiciel basé sur Electron conçu pour configurer l'**ElitePanel**, un panneau de contrôle conçu pour des jeux de simulation tels que Elite Dangerous et American Truck Simulator. Il permet aux utilisateurs de créer, modifier et enregistrer des profils pour les boutons et leviers, offrant des mappings et configurations de touches personnalisés.

## Fonctionnalités

- **Mapping de Touches Personnalisé :** Définissez et personnalisez les touches pour les boutons et leviers.
- **Gestion de Profils :** Créez et enregistrez différents profils pour différents jeux ou configurations.
- **Configuration Interactive :** Modifiez les assignations de touches et les configurations via une interface conviviale.

## Pour Commencer

Pour utiliser l'**ElitePanel Control App**, suivez ces étapes :

1. **Installation :** Clonez ou téléchargez le dépôt.
2. **Dépendances :** Assurez-vous d'avoir Node.js et npm installés.
3. **Configuration :** Exécutez `npm install` pour installer les packages nécessaires.
4. **Lancement :** Exécutez l'application avec `npm start`.

## Utilisation

1. Branchez le panneau via USB sur votre ordinateur.
2. Sélectionnez le bon port COM.
3. Configurez vos touches.
4. Profitez !

## Configuration

L'application vous permet de configurer :

- **Mapping de Touches :** Définir des touches ou actions spécifiques pour chaque bouton ou levier.
- **Profils :** Créer, modifier et supprimer des profils pour différentes configurations de jeu.

## Configuration Matérielle

Le matériel ElitePanel se compose d'un panneau de contrôle physique comprenant des boutons et des leviers. Voici une image du panneau :

![ElitePanel](/readme_sources/images/panelPhoto.png)

## Intégration Arduino (ESP32)

L'ElitePanel est alimenté par un microcontrôleur ESP32. Le code Arduino pour l'intégration ESP32 est disponible dans le répertoire `esp32_code` de ce dépôt.

Il comprend :

 - Un code autonome, qui ne nécessite pas l'**ElitePanel Control App** et est prêt à être utilisé pour ma configuration d'Elite Dangerous. Vous pouvez personnaliser directement le programme pour modifier les touches → [Ici](/esp32_code/standalone/standalone.ino)
 - [WIP] Une version programmable du code, conçue pour fonctionner avec l'**ElitePanel Control App** et avoir des sorties personnalisables → [Ici](/esp32_code/pcProgrammable/pcProgrammable.ino)
