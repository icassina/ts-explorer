open Bs_fetch;

external parseJson : Js_json.t => array SharedTypes.typeItem =
  "Object.create" [@@bs.val];

external tsUrl : string = "tsUrl" [@@bs.val];
external tsId : string = "tsId" [@@bs.val];

let headers =
  HeadersInit.makeWithArray [|
    ("Accept", "application/json"),
    ("Accept-Type", "application/json")
  |];

let config = RequestInit.make credentials::SameOrigin ::headers ();

let data =
  Js.Promise.(
    fetchWithInit tsUrl config |> then_ Response.json |>
    then_ (
      fun typeSystemData => {
        let data = parseJson typeSystemData;
        ReactDOMRe.renderToElementWithId <TypeSystem data /> tsId |> resolve
      }
    )
  );
