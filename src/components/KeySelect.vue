<template>
  <div class="dropdown" id="langList">
    <a id="auto">
      Auto
    </a>
    <a id="en">
      English
    </a>
    <a id="fr">
      Français
    </a>
  </div>
  <button class="btn" id="langBtn">
    <span id="langDpdn">Dropdown</span>
    <i class="bx bx-chevron-up" id="langArrow"></i>
  </button>
</template>

<script>

</script>

<style scoped>
.dropdown:hover .dropdown-content {
  display: block;
}
.dropdown:hover .dropbtn {
  background-color: #111;
}
.btn {
  background-color: #f4b126;
  display: flex;
  align-items: center;
  justify-content: flex-start;
  column-gap: var(--gap);
  padding: 0.6rem;
  cursor: pointer;
  border-radius: var(--radius);
  border: none;
  box-shadow: var(--shadow);
  position: fixed;
  width: 100px;
}
</style>