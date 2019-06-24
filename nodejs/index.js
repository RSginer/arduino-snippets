const five = require('johnny-five');
const board = five.Board();

let servo;
let interval;

board.on('ready', function () {
  servo = five.Servo(2)

  servo.to(10)
});
