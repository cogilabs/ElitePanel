<template>
  <div class="topBar">
    Cogilabs ElitePanel Configurator
  </div>
  <div class="menuBar">
    <section ref="items" class="menuBarItems" @click="toggleDrop">
      <menu-item
        v-for="(item, index) in menuItems"
        :key="index"
        :name="item.name"
        :options="item.options"
        :dropped="dropped"
        :close="item.close"
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
      menuItems: [
        {
          name: "File",
          options: [
            { name: "Option 1" },
            { name: "Option 2" },
            { name: "Option 3" },
          ],
          close: false,
        },
        {
          name: "Profiles",
          options: [
            { name: "Create profile" },
          ],
          close: false,
        },
        {
          name: "Settings",
          options: [
            { name: "Setting 1" },
            { name: "Setting 2" },
            { name: "Setting 3" },
          ],
          close: false,
        },
      ],
    };
  },
  beforeMount() {
    this.loadProfiles();
  },
  methods: {
      receiveEmit(item) {
        this.menuItems.forEach((menuItem) => {
          if (menuItem.name !== item) {
            menuItem.close = !menuItem.close;
          }
        });
      },
      loadProfiles() {
        this.menuItems.forEach((menuItem) => {
          if (menuItem.name == "Profiles") {
            console.log(typeof(menuItem.options))
            menuItem.options.push({ name: "---" });
            for (let i = 1; i <= 20; i++) {
              menuItem.options.push({ name: "Profile " + i });
            }
          }
        });
      },
      toggleDrop() {
        var _this = this
        const closeListener = (e) => {
          if ( _this.catchOutsideClick(e, _this.$refs.items ) )
            window.removeEventListener('click', closeListener) , _this.dropped = false
        }
        window.addEventListener('click', closeListener)
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
/* width */
::-webkit-scrollbar {
  width: 7px;
}

/* Track */
::-webkit-scrollbar-track {
  box-shadow: inset 0 0 5px grey; 
  border-radius: 10px;
}

/* Handle */
::-webkit-scrollbar-thumb {
  background: goldenrod; 
  border-radius: 10px;
}

/* Handle on hover */
::-webkit-scrollbar-thumb:hover {
  background: darkgoldenrod; 
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