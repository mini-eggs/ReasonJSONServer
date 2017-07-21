open Lwt;
open Cohttp_lwt_unix;

/**
 * Start.
 */
let start () => {
  Server.create mode::(`TCP (`Port 8080)) (Server.make callback::Handles.base_handle ())
  |> Lwt_main.run;
};
