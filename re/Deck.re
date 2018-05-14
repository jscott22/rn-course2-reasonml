open BsReactNative;

type card = {
  id: int,
  text: string,
  uri: string,
};

let component = ReasonReact.statelessComponent("Deck");

let renderCards =
    (~cards: array(card), ~renderCard: card => ReasonReact.reactElement) =>
  Array.map(c => renderCard(c), cards);

let make = (~data, ~renderCard, _children) => {
  ...component,
  render: _self =>
    <View>
      (ReasonReact.array(renderCards(~cards=data, ~renderCard)))
    </View>,
};
