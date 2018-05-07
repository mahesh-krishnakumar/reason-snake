type t =
  | ArrowUp
  | ArrowRight
  | ArrowDown
  | ArrowLeft
  | Ignore;

let parseKey = key =>
  switch (key) {
  | "ArrowUp" => ArrowUp
  | "ArrowRight" => ArrowRight
  | "ArrowDown" => ArrowDown
  | "ArrowLeft" => ArrowLeft
  | _ => Ignore
  };

let getDirection = (key, currentDirection) =>
  switch (key, currentDirection) {
  | (ArrowUp, Direction.Up | Direction.Left | Direction.Right) => Direction.Up
  | (ArrowRight, Direction.Right | Direction.Up | Direction.Down) => Direction.Right
  | (ArrowLeft, Direction.Left | Direction.Up | Direction.Down) => Direction.Left
  | (ArrowDown, Direction.Left | Direction.Right | Direction.Down) => Direction.Down
  | (ArrowUp | ArrowDown, Direction.Up | Direction.Down) => currentDirection
  | (ArrowRight | ArrowLeft, Direction.Right | Direction.Left) => currentDirection
  | (Ignore, d) => d
  };