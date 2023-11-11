<template>
  <div class="topBar">

  </div>
  <div>
    <router-view></router-view>
  </div>
</template>

<style>
body {
  user-select: none;
  -webkit-user-select: none;
}
</style>

<style scoped>
.topBar {
  display: block;
  -webkit-app-region: drag;
  height: 32px;
  width: 100vw;
  background-color: #2a414e;
  position: fixed;
  top: 0;
  left: 0;
}
</style>