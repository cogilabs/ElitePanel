<template>
  <div class="bgPicture">
    <img src="/images/topRender.png">
  </div>
  <div class="inputTable">
    <!--Y1 LB LG LW LY LR Y4
        B1                Y5
        B2  Y2 B5   R3 R6 W1
        B3  R1 R2   R4 B6 G3
        B4  G1 G2   R5 Y3 Y6-->
    <table>
      <tr>
        <td></td>
        <td>
          <key-select button="Y1" position="top" />
        </td>
        <td>
          <key-select button="LB" position="top" />
        </td>
        <td>
          <key-select button="LG" position="top" />
        </td>
        <td>
          <key-select button="LW" position="top" />
        </td>
        <td>
          <key-select button="LY" position="top" />
        </td>
        <td>
          <key-select button="LR" position="top" />
        </td>
        <td>
          <key-select button="Y4" position="top" />
        </td>
        <td> </td>
      </tr>
      <tr>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
      </tr>
      <tr>
        <td>
          <key-select button="B1" position="top" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="Y5" position="top" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="Y2" position="top" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="R6" position="top" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="B2" position="top" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="W1" position="top" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="R1" position="top" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="B6" position="top" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="B3" position="bottom" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="G3" position="bottom" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="B4" position="bottom" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="Y6" position="bottom" />
        </td>
      </tr>
      <tr>
        <td>
          <key-select button="G1" position="bottom" />
        </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>
          <key-select button="Y3" position="bottom" />
        </td>
      </tr>
      <tr>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
      </tr>
      <tr>
        <td> </td>
        <td>
          <key-select button="B5" position="bottom" />
        </td>
        <td>
          <key-select button="R2" position="bottom" />
        </td>
        <td>
          <key-select button="G2" position="bottom" />
        </td>
        <td> </td>
        <td>
          <key-select button="R5" position="bottom" />
        </td>
        <td>
          <key-select button="R4" position="bottom" />
        </td>
        <td>
          <key-select button="R3" position="bottom" />
        </td>
        <td> </td>
      </tr>
    </table>
  </div>
</template>

<script setup>
console.log('Application started');
</script>

<script>
export default {
  methods: {
  }
}
</script>

<style>
body {
  font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Helvetica,
    Arial, sans-serif;
  margin: auto;
  max-width: 38rem;
}

.bgPicture {
  display: flex;
  align-content: center;
  justify-content: center;
  align-items: center;
  z-index:-10;
}

img {
  width: 100vw;
  height: 100vh;
}

.inputTable {
  display: flex;
  flex-wrap: nowrap;
  flex-direction: row;
  align-items: center;
  justify-content: center;
  position: fixed;
  left:0;
  top:0;
  width: 100%;
  height: 100%;
  margin: auto;
}

table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 90%;
  height: 90%;
}

td, th {
  /*border: solid 1px black;*/
  text-align: center;
  padding: 8px;
  width: 10%;
  height: 8%;
}
</style>