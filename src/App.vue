<template>
  <div class="topBar">
    Cogilabs Elite Panel Configurator
  </div>
  <div class="menuBar">
    <menu-item 
    button="File"
    :options="fileItems"
    />
    <menu-item 
    button="Profiles"
    :options="profilesItems"
    />
    <menu-item 
    button="Settings"
    :options="settingsItems"
    />
  </div>
  <div>
    <router-view></router-view>
  </div>
</template>

<script>
  export default {
    data() {
      return {
        fileItems: [
          { name: "Option 1" },
          { name: "Option 2" },
          { name: "Option 3" }
        ],
        profilesItems: [
          { name: "Profile 1" },
          { name: "Profile 2" },
          { name: "Profile 3" }
        ],
        settingsItems: [
          { name: "Setting 1" },
          { name: "Setting 2" },
          { name: "Setting 3" }
        ]
      }
    }
  }
</script>

<style>
body {
  user-select: none;
  -webkit-user-select: none;
}
</style>

<style scoped>
.topBar {
  display: flex;
  justify-content: center;
  align-items: center;
  -webkit-app-region: drag;
  height: 32px;
  width: 100vw;
  background-color: #2a414e;
  color: whitesmoke;
  position: fixed;
  top: 0;
  left: 0;
  font-family: Audiowide;
}

.menuBar {
  display: flex;
  justify-content: left;
  align-items: center;
  height: 22px;
  width: 100vw;
  background-color: #3c5d70;
  color: whitesmoke;
  position: fixed;
  top: 32px;
  left: 0;
  z-index: 10;
  font-size: small;
}
</style>