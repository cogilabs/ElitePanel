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

/*.menuBar button {
  border: 0;
  border-right: solid 1px #2a414e;
  background-color: #00000000;
  height: 100%;
}

.menuBar button:hover {
  background-color: #00000020;
}
.menuDropdown {
  border: solid 1px black;
  background-color: #2a414e;
  position: absolute;
  z-index: 2;
  max-height: 45%;
  overflow-y: scroll;
}

.menuDropdown button {
  border: none;
  background: none;
  cursor: pointer;
  width: 100%;
  color: burlywood;
}
.menuDropdown button:hover {
  background: #00000022;
  color: goldenrod;
}*/
</style>