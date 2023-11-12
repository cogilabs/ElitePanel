import { createApp } from 'vue';
import { createRouter, createWebHistory } from 'vue-router'

import App from '/src/App.vue';
import Home from '/src/components/Home.vue';
import KeySelect from '/src/components/KeySelect.vue';
import MenuItem from '/src/components/MenuItem.vue';

const routes = [
  { path: '/', component: Home },
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

const app = createApp(App)
app.use(router) // Use the router in the app

app.component('key-select', KeySelect)
app.component('menu-item', MenuItem)

app.mount('#app')