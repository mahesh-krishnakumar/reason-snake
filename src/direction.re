type t =
  | Up
  | Right
  | Down
  | Left;

type changeDirection =
  | Option(t);