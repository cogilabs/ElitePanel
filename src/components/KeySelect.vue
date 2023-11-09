<template>
  <section class="dropDownMenuWrapper">
    <button class="keySelectButton" ref="menu" @click="openClose">{{ button }}</button>
    <section class="dropdownMenu" v-if="isOpen" >
      <section class="option">
        <button @click="sayKey(button, 'A')">A</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'B')">B</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'C')">C</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'D')">D</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'E')">E</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'F')">F</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'G')">G</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'H')">H</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'I')">I</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'J')">J</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'K')">K</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'L')">L</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'M')">M</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'N')">N</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'O')">O</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'P')">P</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Q')">Q</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'R')">R</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'S')">S</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'T')">T</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'U')">U</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'V')">V</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'W')">W</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'X')">X</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Y')">Y</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Z')">Z</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Escape')">Escape</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Enter')">Enter</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'Tab')">Tab</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'UP')">UP</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'LEFT')">LEFT</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'DOWN')">DOWN</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, 'RIGHT')">RIGHT</button>
      </section>
    </section>
  </section>
</template>

<script>
export default {
  props: [ "button", "position" ], // Menu title from the parent
  data() {
    return {
      isOpen: false // Variable if the menu is open or closed
    }
  },
  methods: {
    openClose() { var _this = this
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
.dropDownMenuWrapper--noTitle {
  padding: 0;
  width: 60px;
  height: 60px;
}

.dropDownMenuWrapper--dark {
  background: #333;
  border: none;
}

.dropdownMenu {
  position: absolute;
}

.keySelectButton {
  width: 100%;
  height: 100%;
}
</style>