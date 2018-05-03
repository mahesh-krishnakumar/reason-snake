open Webapi.Dom;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

let initialSnake = Snake.create([(13, 10), (12, 10), (11, 10), (10, 10)]);

let initialFood = Food.create((15, 9));

let initialDirection = Direction.Right;

let initialWorld = World.create(initialSnake, initialFood, initialDirection);

let state = ref(initialWorld);

let handleTick = () => {
  let oldWorld = state^;
  let newWorld = {
    ...oldWorld,
    snake: Snake.move(oldWorld.snake, Direction.Right),
  };
  state := newWorld;
  Draw.clearScene();
  Draw.drawSnake(state^.snake);
  Draw.drawFood(state^.food);
};

Js.Global.setInterval(handleTick, 300);

let handleEvent = evt => {
  let oldWorld = state^;
  let newDirection =
    evt |> Webapi.Dom.KeyboardEvent.key |> Key.parseKey |> Key.getDirection;
  let newWorld = World.create(oldWorld.snake, oldWorld.food, newDirection);
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);