#pragma once

namespace uk { 

    express_tcp_t dropdown() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( _STRING_(

                .uk-dropdown-hover:hover>ul, .uk-dropdown:has(:checked)>ul, .uk-dropdown>ul:hover {
                    padding: 6px 10px; margin: 0px; width: 100%;
                    color: var(--light); position: absolute;
                    flex-direction: column; display: flex;
                    left: 0; top:100%; list-style: none;
                    background-color: var(--secondary);
                    border-radius: 0px 0px 5px 5px;
                    border: inherit;
                }

                [class*="uk-dropdown"]>ul, .uk-dropdown>input                { display: none; }
                [class*="uk-dropdown"]                                       { position: relative; z-index: 1000; transition: none; padding: 6px 10px; cursor: pointer; }

                .uk-dropdown:has(:checked),.uk-dropdown-bottom:has(:checked) { border-bottom-right-radius: 0; border-bottom-left-radius: 0; }

                .uk-dropdown-top:hover>ul,    .uk-dropdown-top>ul:hover      { left:0; top:unset; bottom:100%; right:unset; }
                .uk-dropdown-bottom:hover>ul, .uk-dropdown-bottom>ul:hover   { left:0; top:100%; bottom:unset; right:unset; }
                .uk-dropdown-right:hover>ul,  .uk-dropdown-right>ul:hover    { left:unset; top:unset; bottom:unset; right:100%; transform:translate( 0px, -50% ); }
                .uk-dropdown-left:hover>ul,   .uk-dropdown-left>ul:hover     { left:100%; top:unset; bottom:unset; right:unset; transform:translate( 0px, -50% ); }

            ));

            for( auto& color : map_t<string_t,string_t>({
                { "primary",   "light" },
                { "secondary", "light" },
                { "success",   "dark"  },
                { "warning",   "light" },
                { "danger",    "light" },
                { "mute",      "dark"  },
                { "light",     "dark"  },
                { "dark",      "light" },
                { "neutral",   "light" }
            }).data() ){ cli.write( regex::format( _STRING_(
                .uk-dropdown-hover-${0}:hover>ul, .uk-dropdown-${0}:has(:checked)>ul, .uk-dropdown-${0}>ul:hover {
                    background-color: var(--${0}); color: var(--${1});
                }
            ), color.first, color.second )); }

        });

        return app;
    }

}