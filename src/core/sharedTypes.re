type typeItem =
  Js.t {
    .
    _type : string,
    _virtual : bool,
    description : string,
    icon : string,
    properties : array (Js.t {. name : string}),
    superTypes : array string,
    root : string
  };
