<template>
  <div class="menuItemDiv">
    <button 
      v-bind:class="[
        'menuItemButton', 
        { open: isOpen }
      ]" 
      ref="menu" @click="openClose">
        {{ button }}
    </button>
    <section class="dropdownMenu" v-if="isOpen" >
      <section 
      v-for="option in options"
      class="option">
        <button @click="console.log(option.name)">{{ option.name }}</button>
      </section>
    </section>
  </div>
</template>

<script>
export default {
  props: [ "button", "options" ], // Menu title from the parent
  data() {
    return {
      isOpen: false // Variable if the menu is open or closed
    }
  },
  methods: {
    openClose() { 
      var _this = this
      const closeListerner = (e) => {
        if ( _this.catchOutsideClick(e, _this.$refs.menu ) )
          window.removeEventListener('click', closeListerner) , _this.isOpen = false
      }
      window.addEventListener('click', closeListerner)
      this.isOpen = !this.isOpen
    },
    catchOutsideClick(event, dropdown)  {
      // When user clicks menu — do nothing
      if( dropdown == event.target )
        return false

      // When user clicks outside of the menu — close the menu
      if( this.isOpen && dropdown != event.target )
        return true
    },
    sayKey(button, key) {
      console.log(button, key);
    }
  }
}
</script>

<style scoped>
.menuItemDiv {
  height: 100%;
  border: 0;
}

.menuItemButton {
  border: 0;
  border-right: solid 1px #2a414e;
  background-color: #00000000;
  height: 100%;
}

.menuItemButton.open, .menuItemButton:hover {
  background: #00000022;
  color: aliceblue;
}

.dropdownMenu {
  display: flex;
  flex-direction: column;
  align-items: baseline;
  position: absolute;
  background-color: #2a414e;
  z-index: 2;
  width: 200px;
}

.option {
  width: 100%;
}

.dropdownMenu button {
  border: none;
  background: none;
  cursor: pointer;
  width: 100%;
  color: burlywood;
  padding: 10px;
  text-align: left;
}
.dropdownMenu button:hover {
  background: #00000022;
  color: goldenrod;
}

.button-content {
  display: flex;
  align-items: center;
}
</style>