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

let getDirection = key =>
  switch (key) {
  | ArrowUp => Direction.Up
  | ArrowRight => Direction.Right
  | ArrowLeft => Direction.Left
  | ArrowDown => Direction.Down
  | Ignore => Direction.Right
  };