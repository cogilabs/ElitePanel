const { app, BrowserWindow, Menu, MenuItem, globalShortcut, Tray, nativeImage } = require('electron');
//const { app, BrowserWindow, Menu, MenuItem, globalShortcut, Tray } = require('electron');
const robot = require('robotjs');
const path = require('path');
const { SerialPort } = require('serialport')
//const appIcon = new Tray('/icons/Large icon.ico')

// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require('electron-squirrel-startup')) {
  app.quit();
}

app.setUserTasks([])

let tray

app.whenReady().then(() => {
  const icon = nativeImage.createFromPath('/icons/Small icon.ico')
  tray = new Tray(icon)

  // note: your contextMenu, Tooltip and Title code will go here!
  
  const contextMenu = Menu.buildFromTemplate([
    { label: 'Item1', type: 'radio' },
    { label: 'Item2', type: 'radio' },
    { label: 'Item3', type: 'radio', checked: true },
    { label: 'Item4', type: 'radio' }
  ])

  tray.setContextMenu(contextMenu)
  tray.setToolTip('This is my application')
  tray.setTitle('This is my title')

})

const createWindow = () => {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 987,
    height: 675,
    useContentSize: true,
    resizable: false,
    icon: '/icons/icon.ico.ico',
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
    },
    titleBarStyle: 'hidden',
    titleBarOverlay: {
      color: '#2a414e',
      symbolColor: 'aliceblue',
      height: 20
    }
  });

  // Create a SerialPort instance and configure it according to your ESP32 setup
  const port = new SerialPort({ path: 'COM4', baudRate: 115200 }) // TODO: Interactive COM Port selection
  let serialInput = "";
  let input = "";

  // Listen for data from the serial port
  port.on('data', (data) => {
    // Handle received data
    const receivedData = data.toString();
    console.log(receivedData);
    /*if (receivedData == "a") {
      robot.keyTap('a');
    }*/
  });

  // and load the index.html of the app.
  if (MAIN_WINDOW_VITE_DEV_SERVER_URL) {
    mainWindow.loadURL(MAIN_WINDOW_VITE_DEV_SERVER_URL);
    mainWindow.webContents.openDevTools();
  } else {
    mainWindow.loadFile(path.join(__dirname, `/../renderer/${MAIN_WINDOW_VITE_NAME}/index.html`));
  }

  // Open the DevTools.
  ////mainWindow.webContents.openDevTools();
};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', createWindow);

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});

app.on('will-quit', () => {
  // Close the serial port when the app is quitting
  /*port.close((err) => {
    if (err) {
      console.error('Error closing serial port:', err);
    }
  });*/

  // Unregister all global shortcuts
  globalShortcut.unregisterAll();
});
// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and import them here.
