<template>
  <div class="topBar">
    Cogilabs Elite Panel Configurator
  </div>
  <div class="menuBar">
    <section ref="items" class="menuBarItems" @click="toggleDrop">
      <menu-item 
      button="File"
      :options="fileItems"
      :dropped="dropped"
      :close="closeFile"
      @hovered="receiveEmit"
      />
      <menu-item 
      button="Profiles"
      :options="profilesItems"
      :dropped="dropped"
      :close="closeProfiles"
      @hovered="receiveEmit"
      />
      <menu-item 
      button="Settings"
      :options="settingsItems"
      :dropped="dropped"
      :close="closeSettings"
      @hovered="receiveEmit"
      />
    </section>
  </div>
  <div>
    <router-view></router-view>
  </div>
</template>

<script>
  export default {
    data() {
      return {
        dropped: false,
        fileItems: [
          { name: "Option 1" },
          { name: "Option 2" },
          { name: "Option 3" }
        ],
        closeFile: false,
        profilesItems: [ // TODO: Make interactive
          { name: "Create profile" },
          { name: "---" },
          { name: "Profile 1" },
          { name: "Profile 2" },
          { name: "Profile 3" }
        ],
        closeProfiles: false,
        settingsItems: [
          { name: "Setting 1" },
          { name: "Setting 2" },
          { name: "Setting 3" }
        ],
        closeSettings: false
      }
    },
    methods: {
      receiveEmit(item) {
        if (item == "File") {
          this.closeProfiles = !this.closeProfiles
          this.closeSettings = !this.closeSettings
        }
        if (item == "Profiles") {
          this.closeFile = !this.closeFile
          this.closeSettings = !this.closeSettings
        }
        if (item == "Settings") {
          this.closeFile = !this.closeFile
          this.closeProfiles = !this.closeProfiles
        }
      }, 
      toggleDrop() {
        var _this = this
        const closeListerner = (e) => {
          if ( _this.catchOutsideClick(e, _this.$refs.items ) )
            window.removeEventListener('click', closeListerner) , _this.dropped = false
        }
        window.addEventListener('click', closeListerner)
        this.dropped = !this.dropped
      },
      catchOutsideClick(event, items)  {
        // When user clicks menu — do nothing
        if( items.contains(event.target) )
          return false

        // When user clicks outside of the menu — close the menu
        if( this.dropped && !items.contains(event.target) )
          return true
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
  color: aliceblue;
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
  color: aliceblue;
  position: fixed;
  top: 32px;
  left: 0;
  z-index: 10;
  font-size: small;
}

.menuBarItems {
  display: contents;
}
</style>