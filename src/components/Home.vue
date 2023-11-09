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
        <td> </td>
        <td>Y1</td>
        <td>LB</td>
        <td>LG</td>
        <td>LW</td>
        <td>LY</td>
        <td>LR</td>
        <td>Y4</td>
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
        <td>B1</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>Y5</td>
      </tr>
      <tr>
        <td>Y2</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>R6</td>
      </tr>
      <tr>
        <td>B2</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>W1</td>
      </tr>
      <tr>
        <td>R1</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>B6</td>
      </tr>
      <tr>
        <td>B3</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>G3</td>
      </tr>
      <tr>
        <td>B4</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>Y6</td>
      </tr>
      <tr>
        <td>G1</td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td>Y3</td>
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
        <td>B5</td>
        <td>R2</td>
        <td>G2</td>
        <td> </td>
        <td>R5</td>
        <td>R4</td>
        <td>R3</td>
        <td> </td>
      </tr>
    </table>
  </div>
</template>

<script setup>
console.log('This message is being logged by "App.vue", included via Vite');
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