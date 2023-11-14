<template>
  <div class="menuItemDiv">
    <button 
      v-bind:class="[
        'menuItemButton', 
        { open: isOpen }
      ]" 
      ref="menu" @click="toggleMenu" @mouseover="openOnHover">
        {{ name }}
    </button>
    <section class="dropdownMenu" v-if="isOpen" >
      <section 
        v-for="option in options"     
        v-bind:class="['option', { separator: option.name =='---'}]"
      >
        <button @click="optionAction(option)">{{ option.name }}</button>
      </section>
    </section>
  </div>
</template>

<script>
export default {
  props: [ "name", "options", "dropped", "close" ],
  data() {
    return {
      isOpen: false
    }
  },
  watch: {
    dropped(newDropped) {
      if (!newDropped) {
        this.isOpen = false;
      }
    },
    close() {
      this.isOpen = false;
    }
  },
  methods: {
    toggleMenu() {
      this.isOpen = !this.isOpen;
    },
    openOnHover() {
      if (this.dropped) {
        this.$emit('hovered', this.name);
        this.isOpen = true;
      }
    },
    optionAction(option) {
      if (option.name != "---") {
        console.log(option.name)
      }
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
  margin: 5px 3px;
  border-radius: 5px;
  max-height: 90vh;
  overflow-y: auto;
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

.separator button, .separator button:hover {
  border-bottom: solid 1px burlywood;
  color: #00000000;
  background: #00000000;
  height: 0;
  padding: 4px;
  cursor: unset;
  margin: 0 15px;
  width: -webkit-fill-available;
}
</style>