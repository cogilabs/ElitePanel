<template>
  <section class="dropDownMenuWrapper">
    <button 
      v-bind:class="[
        'keySelectButton', 
        { bottom: position == 'bottom' }, 
        { top: position != 'bottom' }, 
        { open: isOpen }
      ]" 
      ref="menu" @click="openClose">
        {{ button }}
        <span class="arrow">^</span>
    </button>
    <section v-bind:class="['dropdownMenu', { bottom: position == 'bottom' }, { top: position != 'bottom' }]" v-if="isOpen" >
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
        <button @click="sayKey(button, '↑')">↑</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, '←')">←</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, '↓')">↓</button>
      </section>
      <section class="option">
        <button @click="sayKey(button, '→')">→</button>
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
.dropdownMenu {
  border: solid 1px black;
  background-color: #2a414e;
  position: absolute;
  z-index: 2;
  max-height: 43%;
  overflow-y: scroll;
  border-radius: 5px;
}
.dropdownMenu.bottom {
  transform: translateY(-106.5%);
}

.dropdownMenu button {
  border: none;
  background: none;
  cursor: pointer;
  width: 100%;
  color: burlywood;
}
.dropdownMenu button:hover {
  background: #00000022;
  color: goldenrod;
}

.keySelectButton {
  display: flex;
  flex-direction: row;
  justify-content: space-between;
  align-items: center;
  width: 100%;
  height: 100%;
  cursor: pointer;
  position: relative;
  font-weight: bold;
  color: white;
  background-color: #263341;
  box-shadow: 0px 0px 4px 1px #94a1b0;
  border-radius: 5px;
}

.button-content {
  display: flex;
  align-items: center;
}

.arrow {
  display: inline-block;
  transform-origin: center;
  cursor: pointer;
}

.arrow {
  transition: transform 0.3s ease;
}

.top .arrow {
  transform: rotate(180deg);
}

.open {
  border-style: inset;
  box-shadow: 0px 0px 4px 1px #4c535b;
}

.top.open .arrow {
  transform: rotate(360deg);
}

.bottom.open .arrow {
  transform: rotate(180deg);
}
</style>