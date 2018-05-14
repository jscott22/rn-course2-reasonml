open BsReactNative;

type animationState = {
  top: Animated.Value.t,
  left: Animated.Value.t,
};

let component = ReasonReact.statelessComponent("Ball");

let styles =
  StyleSheet.create(
    Style.(
      {
        "ball":
          style([
            height(Pt(60.)),
            width(Pt(60.)),
            borderWidth(30.),
            borderRadius(30.),
            borderColor(String("black")),
          ]),
      }
    ),
  );

let ballPosition = {
  top: Animated.Value.create(0.),
  left: Animated.Value.create(0.),
};

let startAnimation = () =>
  Animated.CompositeAnimation.start(
    Animated.parallel(
      [|
        Animated.Spring.animate(
          ~value=ballPosition.top,
          ~toValue=`raw(500.),
          (),
        ),
        Animated.Spring.animate(
          ~value=ballPosition.left,
          ~toValue=`raw(200.),
          (),
        ),
      |],
      [%bs.raw "{stopTogether: true}"],
    ),
    (),
  );

let make = _children => {
  ...component,
  render: _self =>
    <Animated.View
      style=Style.(
              style([
                top(Animated(ballPosition.top)),
                left(Animated(ballPosition.left)),
              ])
            )>
      <TouchableOpacity onPress=startAnimation>
        <View style=styles##ball />
      </TouchableOpacity>
    </Animated.View>,
};
