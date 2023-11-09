import { createApp } from 'vue';
import { createRouter, createWebHistory } from 'vue-router'

import App from '/src/App.vue';
import Home from '/src/components/Home.vue';

const routes = [
  { path: '/', component: Home },
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

const app = createApp(App)
app.use(router) // Use the router in the app

app.mount('#app')